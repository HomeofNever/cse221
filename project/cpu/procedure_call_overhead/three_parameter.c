#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <sys/wait.h>
#include <sys/mman.h>

void three_parameter(int a, int b, int c){}

int main() {
  print_message(_GENERIC_INFO, "Start Three Parameter Time Test: fork()\n");
  static struct Timer timer;

  start_timer(&timer);

  three_parameter(0,1,2);

  end_timer(&timer);

  uint64_t res = calc_diff(&timer);
  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}