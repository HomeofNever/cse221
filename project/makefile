main:main.c | mkdist
	gcc -O0 -Wall -o dist/main main.c

cpu_context_switch_thread:./cpu/context_switch/thread.c | mkdist
	gcc -pthread -O0 -Wall -o dist/context_switch_thread ./cpu/context_switch/thread.c

cpu_context_switch_process:./cpu/context_switch/process.c | mkdist
	gcc -O0 -Wall -o dist/context_switch_process ./cpu/context_switch/process.c

cpu_procedure_call_zero_parameter:./cpu/procedure_call_overhead/zero_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_zero_parameter ./cpu/procedure_call_overhead/zero_parameter.c

cpu_procedure_call_one_parameter:./cpu/procedure_call_overhead/one_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_one_parameter ./cpu/procedure_call_overhead/one_parameter.c

cpu_procedure_call_two_parameter:./cpu/procedure_call_overhead/two_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_two_parameter ./cpu/procedure_call_overhead/two_parameter.c

cpu_procedure_call_three_parameter:./cpu/procedure_call_overhead/three_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_three_parameter ./cpu/procedure_call_overhead/three_parameter.c

cpu_procedure_call_four_parameter:./cpu/procedure_call_overhead/four_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_four_parameter ./cpu/procedure_call_overhead/four_parameter.c

cpu_procedure_call_five_parameter:./cpu/procedure_call_overhead/five_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_five_parameter ./cpu/procedure_call_overhead/five_parameter.c

cpu_procedure_call_six_parameter:./cpu/procedure_call_overhead/six_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_six_parameter ./cpu/procedure_call_overhead/six_parameter.c

cpu_procedure_call_seven_parameter:./cpu/procedure_call_overhead/seven_parameter.c | mkdist
	gcc -pthread -O0 -Wall -o dist/procedure_call_seven_parameter ./cpu/procedure_call_overhead/seven_parameter.c

cpu_procedure_system_call:./cpu/system_call_overhead/process.c | mkdist
	gcc -pthread -O0 -Wall -o dist/system_call_process ./cpu/system_call_overhead/process.c

cpu_task_creation_thread:./cpu/task_creation/thread.c | mkdist
	gcc -pthread -O0 -Wall -o dist/task_creation_thread ./cpu/task_creation/thread.c

cpu_task_creation_process:./cpu/task_creation/process.c | mkdist
	gcc -O0 -Wall -o dist/task_creation_process ./cpu/task_creation/process.c

cpu_task_reading_time:cpu/measurement_overhead/read_time.c | mkdist
	gcc -O0 -Wall -o dist/reading_time ./cpu/measurement_overhead/read_time.c

cpu_task_loop_overhead:cpu/measurement_overhead/loop_overhead.c | mkdist
	gcc -O0 -Wall -o dist/loop_overhead ./cpu/measurement_overhead/loop_overhead.c

memory_bandwidth_read:memory/bandwidth/read.c | mkdist
	gcc -O0 -Wall -o dist/memory_bandwidth_read ./memory/bandwidth/read.c

memory_bandwidth_write:memory/bandwidth/write.c | mkdist
	gcc -O0 -Wall -o dist/memory_bandwidth_write ./memory/bandwidth/write.c

ram_access_time:memory/access_time/ram_access_time.c | mkdist
	gcc -O0 -Wall -o dist/ram_access_time ./memory/access_time/ram_access_time.c

page_fault_service:memory/page_fault_service/page_fault.c | mkdist
	gcc -O0 -Wall -o dist/page_fault memory/page_fault_service/page_fault.c
	
network_rtt_server:network/rtt/server.c | mkdist
	gcc -O3 -Wall -o dist/network_rtt_server ./network/rtt/server.c

network_rtt_remote:network/rtt/remote.c | mkdist
	gcc -O3 -Wall -o dist/network_rtt_remote ./network/rtt/remote.c

network_rtt_lo:network/rtt/lo.c | mkdist
	gcc -O3 -Wall -o dist/network_rtt_lo ./network/rtt/lo.c

network_setup_lo:network/setup/lo_up.c | mkdist
	gcc -O3 -Wall -o dist/network_setup_lo network/setup/lo_up.c

network_teardown_lo:network/setup/lo_down.c | mkdist
	gcc -O3 -Wall -o dist/network_teardown_lo network/setup/lo_down.c

network_setup_remote:network/setup/remote_up.c | mkdist
	gcc -O3 -Wall -o dist/network_setup_remote network/setup/remote_up.c

network_teardown_remote:network/setup/remote_up.c | mkdist
	gcc -O3 -Wall -o dist/network_teardown_remote network/setup/remote_down.c

network_setup_server:network/setup/server.c | mkdist
	gcc -O3 -Wall -o dist/network_setup_server ./network/setup/server.c

network_bandwidth_lo:network/bandwidth/client_lo.c | mkdist
	gcc -O3 -Wall -o dist/network_bandwidth_lo ./network/bandwidth/client_lo.c

network_bandwidth_remote:network/bandwidth/client_remote.c | mkdist
	gcc -O3 -Wall -o dist/network_bandwidth_remote ./network/bandwidth/client_remote.c

network_bandwidth_server:network/bandwidth/server.c | mkdist
	gcc -O3 -Wall -o dist/network_bandwidth_server ./network/bandwidth/server.c

file_cache_size:file_system/file_cache_size/file_cache_size.c | mkdist
	gcc -O3 -Wall -o dist/file_cache_size ./file_system/file_cache_size/file_cache_size.c

file_read_time:file_system/file_read_time/file_read_time.c| mkdist
	gcc -pthread -O0 -Wall -o dist/file_read_time ./file_system/file_read_time/file_read_time.c

remote_file_read_time:file_system/remote_file_read_time/remote_file_read_time.c | mkdist
	gcc -pthread -O0 -Wall -o dist/remote_file_read_time ./file_system/remote_file_read_time/remote_file_read_time.c

contention:file_system/contention/contention.c | mkdist
	gcc -pthread -O0 -Wall -o dist/contention ./file_system/contention/contention.c

run_test:./run_test.py
	python3 ./run_test.py

all: main \
	 cpu_task_reading_time cpu_task_loop_overhead \
	 cpu_procedure_call_zero_parameter \
	 cpu_procedure_call_one_parameter \
	 cpu_procedure_call_two_parameter \
	 cpu_procedure_call_three_parameter \
	 cpu_procedure_call_four_parameter \
	 cpu_procedure_call_five_parameter \
	 cpu_procedure_call_six_parameter \
	 cpu_procedure_call_seven_parameter \
	 cpu_procedure_system_call \
	 cpu_task_creation_thread cpu_task_creation_process cpu_context_switch_process cpu_context_switch_thread \
	 memory_bandwidth_read memory_bandwidth_write page_fault_service \
	 network_rtt_server \
	 network_rtt_remote \
	 network_rtt_lo \
	 network_setup_lo network_teardown_lo network_setup_remote network_teardown_remote \
	 network_bandwidth_lo network_bandwidth_remote network_bandwidth_server \
	 ram_access_time \
	 file_cache_size file_read_time remote_file_read_time contention
	 

mkdist:
	mkdir -p dist

clean: 
	  $(RM) -r dist