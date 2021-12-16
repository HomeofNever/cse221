#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <sys/wait.h>
#include <sys/mman.h>

static struct Timer *timer;

int main() {
  print_message(_GENERIC_INFO, "Start CPU Context Switch Time Test: fork()\n");

  pid_t pid;
  timer = mmap(NULL, sizeof *timer, PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  start_timer(timer);

  // Let's make a pipe
  int p[2];
  int pipe_rc = pipe( p );
  if (pipe_rc == -1){
    print_error_message("Unable to create pipe.");
  }
  char rec;

  // Let's write it first, so we can make child read and count time there
  if (write(p[1], "a", 1) == -1){
    print_error_message("Unable to write data.");
  }

  pid = fork();

  if (pid == -1) {
    print_error_message("Unable to fork, exiting...\n");
  }

  if (pid == 0) {
    start_timer(timer); // Start from Child
    if (read(p[0], &rec, 1) == -1) {
      print_error_message("Unable to read data.");
    }
    return 0;
  } else {
    wait(NULL);
    end_timer(timer);
  }

  uint64_t res = calc_diff(timer);

  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}
