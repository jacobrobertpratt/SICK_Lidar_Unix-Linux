#include "../include/udraw.h"

int udraw_drawPoint(uint32_t * data, int stride, int xpos, int ypos, int radius) {
    
    if(!data) return 1;
    
    uint32_t * strt = data;
    uint32_t * ptr = data;
    uint32_t * row = data;
    ptr += xpos + stride * ypos;
    row = ptr;
    uint32_t color = 0xff00ff00;
    
    *ptr = color;
    
    int i;
    for(i = 0; i < radius; i++){
        int x = 0, y = i;
        int d = 3 - 2 * i;
        
    
        while (y >= x) {
            x++;

            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            }
            else
                d = d + 4 * x + 6;
            
            ptr = strt + (x + xpos) + stride * (y + ypos);
            *ptr = color;
            ptr = strt + (xpos - x) + stride * (ypos - y);
            *ptr = color;
            ptr = strt + (xpos - x) + stride * (ypos + y);
            *ptr = color;
            ptr = strt + (xpos + x) + stride * (ypos - y);
            *ptr = color;
            ptr = strt + (y + xpos) + stride * (x + ypos);
            *ptr = color;
            ptr = strt + (xpos - y) + stride * (ypos - x);
            *ptr = color;
            ptr = strt + (xpos - y) + stride * (ypos + x);
            *ptr = color;
            ptr = strt + (xpos + y) + stride * (ypos - x);
            *ptr = color;
            
        }
    }
    
    return 0;
}
