#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <pthread.h>
#include <sys/mman.h>


static struct Timer *timer;

void * useless_thread() {
  end_timer(timer);
  return 0; // Do Nothing, happy :)
}

int main() {
  print_message(_GENERIC_INFO, "Start CPU Task Creation Test: Thread\n");
  timer = mmap(NULL, sizeof *timer, PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  pthread_t pid;

  start_timer(timer);

  pthread_create(&pid, NULL, useless_thread, NULL);

  pthread_join(pid, NULL); // Don't care about result, but wait for child write back end timer.

  uint64_t res = calc_diff(timer);

  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}