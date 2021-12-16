#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
#include <sys/wait.h>
#include <sys/mman.h>

static struct Timer *timer;

// This only run one fork and get the result
int main() {
  print_message(_GENERIC_INFO, "Start CPU Task Creation Test: fork()\n");

  pid_t pid;
  timer = mmap(NULL, sizeof *timer, PROT_READ | PROT_WRITE,
                  MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  start_timer(timer);

  pid = fork();

  if (pid == -1) {
    print_error_message("Unable to fork, exiting...\n");
  }

  if (pid == 0) {
    end_timer(timer);
    return 0; // We are child, simply exit
  } else {
    wait(NULL); // We don't care about the status
  }

  end_timer(timer);

  uint64_t res = calc_diff(timer);

  print_message(_GENERIC_INFO, "Result: ");
  print_uint64(res);

  return 0;
}
