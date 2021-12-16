#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <sys/wait.h>
#include <sys/mman.h>



void one_parameter(int a){
}

int main() {
  static struct Timer timer;
  print_message(_GENERIC_INFO, "Start One Parameter Time Test: fork()\n");

  start_timer(&timer);

  one_parameter(0);

  end_timer(&timer);

  uint64_t res = calc_diff(&timer);
  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}