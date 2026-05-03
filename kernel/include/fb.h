#pragma once

#ifndef FB_H
#define FB_H

#include <stdint.h>
#include <stdio.h>

typedef struct Framebuffer {
  uint8_t *virt;
  size_t   phys;

  size_t width, height, bpp, pitch;
  size_t red_shift, red_size;
  size_t green_shift, green_size;
  size_t blue_shift, blue_size;
} Framebuffer;

extern Framebuffer fb;

#define drawPixel(x, y, r, g, b)                                               \
  do {                                                                         \
    fb.virt[((x) + (y) * fb.width) * 4] = (b);                                 \
    fb.virt[((x) + (y) * fb.width) * 4 + 1] = (g);                             \
    fb.virt[((x) + (y) * fb.width) * 4 + 2] = (r);                             \
    fb.virt[((x) + (y) * fb.width) * 4 + 3] = 0;                               \
  } while (0)

#endif
