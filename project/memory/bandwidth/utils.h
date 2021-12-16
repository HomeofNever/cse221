#ifndef _MEMORY_UTILS_H
#define _MEMORY_UTILS_H
#include <string.h>
#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"

#define CACHE_SIZE (25*1024*1000*8* 2) // 25MB -- L3, we double it to make sure
#define ARR_LEN 1025


#define WOP(i) current[i] = 1;

#define obfs_memory \
    char *ram1 = malloc(CACHE_SIZE); \
    char *ram2 = malloc(CACHE_SIZE); \
    memcpy(ram1, ram2, CACHE_SIZE); \

#define prt_speed(time) printf("%.5f", sizeof(int) * 1.0 * 1025 * CPU_FRQ / 1000 / 1024 / time);

#endif