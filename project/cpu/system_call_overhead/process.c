#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <stdio.h>
#include <unistd.h>


int main() {
  print_message(_GENERIC_INFO, "Start System Call Overhead Time Test: fork()\n");

  static struct Timer timer;
  start_timer(&timer);

  int pid = getpid();

  end_timer(&timer);

  uint64_t res = calc_diff(&timer);
  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}