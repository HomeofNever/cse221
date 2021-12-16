#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <sys/wait.h>
#include <sys/mman.h>



void seven_parameter(int a, int b, int c,int d,int e,int f,int g){
}

int main() {
  static struct Timer timer;
  print_message(_GENERIC_INFO, "Start Seven Parameter Time Test: fork()\n");

  start_timer(&timer);

  seven_parameter(0,1,2,3,4,5,6);

  end_timer(&timer);

  uint64_t res = calc_diff(&timer);
  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}