#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"

int main () {
    print_message(_GENERIC_INFO, "Starting CPU Reading Time Overhead Test\n");

    uint32_t cycles_low, cycles_high, cycles_low1, cycles_high1;
    uint64_t start, end, measurement;

    asm volatile ("CPUID\n\t"
                  "RDTSC\n\t"
                  "mov %%edx, %0\n\t"
                  "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
    "%rax", "%rbx", "%rcx", "%rdx");
/***********************************/
/*call the function to measure here*/
/***********************************/
    asm volatile("RDTSCP\n\t"
                 "mov %%edx, %0\n\t"
                 "mov %%eax, %1\n\t"
                 "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::
    "%rax", "%rbx", "%rcx", "%rdx");

    start = ( ((uint64_t)cycles_high << 32) | cycles_low );
    end = ( ((uint64_t)cycles_high1 << 32) | cycles_low1 );

    measurement = end-start;


    print_message(_GENERIC_INFO, "Result is:\n");
    print_uint64(measurement);
}


