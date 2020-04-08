
#include "../include/usave.h"

static void encode(AVCodecContext *enc_ctx, AVFrame *frame, AVPacket *pkt, FILE *outfile)
{
    GOTHERE
    int ret;
    /* send the frame to the encoder */
    if (frame)
        printf("Send frame %3"PRId64"\n", frame->pts);
    
    GOTHERE
    
    ret = avcodec_send_frame(enc_ctx, frame);
    if (ret < 0) {
        fprintf(stderr, "Error sending a frame for encoding\n");
        exit(1);
    }
    GOTHERE
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
    GOTHERE
    
}

int save_frameAsJPEG() {
    // Set up a frame
    
    
    
    AVCodec * codec = NULL;
    AVCodecContext * context = NULL;
    AVFrame *  frame = NULL;
    AVPacket * packet = NULL;
    FILE * file = NULL;
    int ret = 0;
    
    // Set up File
    file = fopen("0000.jpg","wb");
    if(!file)
        return 1;
    
    GOTHERE
    
    // Alloc Codec
    codec = avcodec_find_encoder(AV_CODEC_ID_MJPEG);
    if(!codec)
        return 1;
    
    GOTHERE
    
    // Alloc Context
    context = avcodec_alloc_context3(codec);
    if(!context)
        return 2;
    
    GOTHERE
    
    // Alloc Packet
    packet = av_packet_alloc();
    if (!packet)
        return 3;
    
    GOTHERE
    
    
    
    context->width = 720;
    GOTHERE
    context->height = 480;
    GOTHERE
    context->pix_fmt = AV_PIX_FMT_YUVJ420P;
    context->time_base = (AVRational){1, 25};
    context->framerate = (AVRational){25, 1};
    
    GOTHERE
    
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
    
    GOTHERE
    
    // Alloc Frame buffer
    ret = av_frame_get_buffer(frame, 16);
    if (ret < 0) {
        fprintf(stderr, "Could not allocate the video frame data\n");
        exit(1);
    }
    
    GOTHERE
    
    // encode video
    fflush(stdout);
    /* make sure the frame data is writable */
    ret = av_frame_make_writable(frame);
    if (ret < 0)
        exit(1);
    
    GOTHERE
    // Set to a black screen
    //memset(frame->data,0,sizeof(uint8_t) * frame->width * frame->height * 2);
    
    GOTHERE
    encode(context,frame,packet,file);
    
    
    GOTHERE
    fwrite(packet->data, 1, packet->size, file);
    fclose(file);
    
    GOTHERE
    avcodec_free_context(&context);
    av_frame_free(&frame);
    av_packet_free(&packet);
    return 0;
}
