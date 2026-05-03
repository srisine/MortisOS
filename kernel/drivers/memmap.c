#include <memmap.h>

__attribute__((used, section(".limine_requests")))
volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST_ID,
    .revision = 0
};

struct limine_memmap_response* memmap;

void pmm_init() {
    memmap = memmap_request.response;

    if (memmap == NULL) {
        return;
    }
   


}
