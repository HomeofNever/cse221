#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <pthread.h>
#include <sys/mman.h>

int p[2];
static struct Timer *timer;

void * useful_thread() {
  char rec;
  start_timer(timer);
  if (read(p[0], &rec, 1) == -1) {
    print_error_message("Unable to read data.");
  }
  return 0;
}

int main() {
  print_message(_GENERIC_INFO, "Start CPU Task Creation Test: Thread\n");

  timer = mmap(NULL, sizeof *timer, PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  // Let's make a pipe
  int pipe_rc = pipe( p );
  if (pipe_rc == -1){
    print_error_message("Unable to create pipe.");
  }

  // Let's write it first, so we can make child read and count time there
  if (write(p[1], "a", 1) == -1){
    print_error_message("Unable to write data.");
  }

  pthread_t pid;

  pthread_create(&pid, NULL, useful_thread, NULL);

  pthread_join(pid, NULL);
  end_timer(timer);

  uint64_t res = calc_diff(timer);

  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}