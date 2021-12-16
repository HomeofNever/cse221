#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#define LOOP_ITERATIONS 100000

int main () {
    struct Timer timer;

    start_timer(&timer);

    int i = 0;
    for(; i < LOOP_ITERATIONS; i++){};

    end_timer(&timer)

    print_uint64(calc_diff(&timer)/LOOP_ITERATIONS);
}