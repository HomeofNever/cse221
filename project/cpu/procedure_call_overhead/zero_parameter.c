#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <sys/wait.h>
#include <sys/mman.h>

void zero_parameter(){
}

int main() {
  print_message(_GENERIC_INFO, "Start One Parameter Time Test: fork()\n");

  static struct Timer timer;
  start_timer(&timer);

  zero_parameter();

  end_timer(&timer);

  uint64_t res = calc_diff(&timer);
  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}