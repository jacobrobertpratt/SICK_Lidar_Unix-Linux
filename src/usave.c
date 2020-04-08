
#include "../include/usave.h"

static void encode(AVCodecContext *enc_ctx, AVFrame *frame, AVPacket *pkt, FILE *outfile) {
    int ret;
    /* send the frame to the encoder */
    if (frame)
        printf("Send frame %3"PRId64"\n", frame->pts);
    
    ret = avcodec_send_frame(enc_ctx, frame);
    if (ret < 0) {
        fprintf(stderr, "Error sending a frame for encoding\n");
        exit(1);
    }
    
    while (ret >= 0) {
        ret = avcodec_receive_packet(enc_ctx, pkt);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
            return;
        else if (ret < 0) {
            fprintf(stderr, "Error during encoding\n");
            exit(1);
        }
        printf("Write packet %3"PRId64" (size=%5d)\n", pkt->pts, pkt->size);
        fwrite(pkt->data, 1, pkt->size, outfile);
        av_packet_unref(pkt);
    }
}

int save_frameAsJPEG(uint32_t * data, int pic_width, int pic_height, int bitperpix, char * name, int idx) {
    
    // Set up a frame variables
    AVCodec * codec = NULL;
    AVCodecContext * context = NULL;
    AVFrame *  frame = NULL;
    AVPacket * packet = NULL;
    struct SwsContext * sws_context = NULL;
    FILE * file = NULL;
    int ret = 0;
    
    char pic_name[256];
    memset(pic_name,0,sizeof(pic_name));
    sprintf(pic_name,"%s_%04d.jpg",name,idx);
    
    int dst_linesize[4] = {(bitperpix/8) * pic_width};
    printf("dst_linesize[0]: %d\n",dst_linesize[0]);
    // Set up File
    file = fopen(pic_name,"wb");
    if(!file)
        return 1;
    
    // Alloc Codec
    codec = avcodec_find_encoder(AV_CODEC_ID_MJPEG);
    if(!codec)
        return 1;
    
    // Alloc Context
    context = avcodec_alloc_context3(codec);
    if(!context)
        return 2;
    
    // Alloc Packet
    packet = av_packet_alloc();
    if (!packet)
        return 3;
    
    context->width = pic_width;
    context->height = pic_height;
    context->pix_fmt = AV_PIX_FMT_YUVJ420P;
    context->time_base = (AVRational){1, 25};
    context->framerate = (AVRational){25, 1};
    
    if (avcodec_open2(context, codec, NULL) < 0)
        return -1;
    
    // Alloc Frame
    frame = av_frame_alloc();
    if (!frame) {
        fprintf(stderr, "Could not allocate video frame\n");
        exit(1);
    }
    frame->format = context->pix_fmt;
    frame->width  = context->width;
    frame->height = context->height;
    
    // Alloc Frame buffer
    ret = av_frame_get_buffer(frame, bitperpix);
    if (ret < 0) {
        fprintf(stderr, "Could not allocate the video frame data\n");
        exit(1);
    }
    
    // Allocate sws Context
    sws_context = sws_getContext(context->width, context->height, AV_PIX_FMT_RGBA, context->width, context->height, AV_PIX_FMT_YUVJ420P, SWS_BILINEAR, 0, 0, 0);
    if(!sws_context)
        return 1;
    
    // git dst data
    uint8_t * dst_data[4] = {(uint8_t*)data, 0, 0, 0};
    
    sws_scale(sws_context, (const uint8_t * const*)dst_data, dst_linesize, 0, context->height, frame->data, frame->linesize);

    // encode video
    fflush(stdout);
    /* make sure the frame data is writable */
    ret = av_frame_make_writable(frame);
    if (ret < 0)
        exit(1);
    
    frame->pts = 0;
    
    encode(context,frame,packet,file);
    
    fwrite(packet->data, 1, packet->size, file);
    fclose(file);
    
    avcodec_free_context(&context);
    av_frame_free(&frame);
    av_packet_free(&packet);
    
    return 0;
}
