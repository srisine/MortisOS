#include <VGA.h>

__attribute__((used, section(".limine_requests")))
volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

__attribute__((used, section(".limine_requests")))
volatile struct limine_hhdm_request hhdm_request = {
    .id = LIMINE_HHDM_REQUEST_ID,
    .revision = 0
};

void initVGA(){
    struct limine_framebuffer *fbfr = framebuffer_request.response->framebuffers[0]; 
    uint64_t hhdm_offset = hhdm_request.response->offset;
    fb.virt = (uint8_t *)fbfr->address;
    fb.phys = (size_t)fb.virt-hhdm_offset;
    fb.height = fbfr->height;
    fb.width = fbfr->width;
    fb.pitch = fbfr->pitch;
    fb.bpp = fbfr->bpp;

    fb.red_shift = fbfr->red_mask_shift;
    fb.red_size = fbfr->red_mask_size;

    fb.green_shift = fbfr->green_mask_shift;
    fb.green_size = fbfr->green_mask_size;

    fb.blue_shift = fbfr->blue_mask_shift;
    fb.blue_size = fbfr->blue_mask_size;
}
