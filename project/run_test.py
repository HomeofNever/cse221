import subprocess
import time
import json
import statistics
import sys
# Helper to run test multiple times

trials = 5
available_tests = {
        "procedure_call/zero": {
            "exec": "procedure_call_zero_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/one": {
            "exec": "procedure_call_one_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/two": {
            "exec": "procedure_call_two_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/three": {
            "exec": "procedure_call_three_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/four": {
            "exec": "procedure_call_four_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/five": {
            "exec": "procedure_call_five_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/six": {
            "exec": "procedure_call_six_parameter",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "procedure_call/seven": {
            "exec": "procedure_call_seven_parameter",
            "iteration": 1000
        },
        "system_call/process": {
            "exec": "system_call_process",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "task_creation/process": {
            "exec": "task_creation_process",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "task_creation/thread": {
            "exec": "task_creation_thread",
            "iteration":1000,
            "type": "int",
            "before_start": ""
        },
        "context_switch/process": {
            "exec": "context_switch_process",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "context_switch/thread": {
            "exec": "context_switch_thread",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "measurement_overhead/read_time": {
            "exec": "reading_time",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "measurement_overhead/loop_overhead": {
            "exec": "loop_overhead",
            "iteration": 1000,
            "type": "int",
            "before_start": ""
        },
        "memory_bandwidth/read": {
            "exec": "memory_bandwidth_read",
            "iteration": 100,
            "type": "float",
            "before_start": ""
        },
        "memory_bandwidth/write": {
            "exec": "memory_bandwidth_write",
            "iteration": 100,
            "type": "float",
            "before_start": ""
        },
        "network_rtt/lo": {
            "exec": "network_rtt_lo",
            "iteration": 100,
            "type": "float",
            "before_start": "network_rtt_server"
        },
        "network_rtt/remote": {
            "exec": "network_rtt_remote",
            "iteration": 100,
            "type": "float",
            "before_start": "network_rtt_server"
        },
        "network_setup/lo": {
            "exec": "network_setup_lo",
            "iteration": 100,
            "type": "float",
            "before_start": "network_setup_server"
        },
        "network_teardown/lo": {
            "exec": "network_teardown_lo",
            "iteration": 100,
            "type": "float",
            "before_start": "network_setup_server"
        },
        "network_setup/remote": {
            "exec": "network_setup_remote",
            "iteration": 100,
            "type": "float",
            "before_start": "network_setup_server"
        },
        "network_teardown/remote": {
            "exec": "network_teardown_remote",
            "iteration": 100,
            "type": "float",
            "before_start": "network_setup_server"
        },
        "network_bandwidth/lo": {
            "exec": "network_bandwidth_lo",
            "iteration": 100,
            "type": "float",
            "before_start": "network_bandwidth_server"
        },
        "network_bandwidth/remote": {
            "exec": "network_bandwidth_remote",
            "iteration": 100,
            "type": "float",
            "before_start": "network_bandwidth_server"
        },
        "file_system/file_read_time": {
            "exec": "file_read_time",
            "iteration": 100,
            "type": "int",
            "before_start": ""
        }
}

exec_location = "./dist"

# main section
for task_name in available_tests:
    task = available_tests[task_name]
    trial = []
    run_command = exec_location + '/' + task['exec']
    write_result = exec_location + '/' + task['exec'] + str(time.time()) + '.json'
    print("Running Test for: " + task_name + ", each iter: " + str(task['iteration']))
    if task['before_start'] != "":
        input("!!! Please make sure {} has started. Press enter to continue.".format(task['before_start']))

    for i in range(trials):
        print("[Partial] trial " + str(i))

        res = []
        for i in range(task['iteration']):
            ret = subprocess.run(["taskset", "--cpu-list", "30", run_command], stdout=subprocess.PIPE).stdout.decode('utf-8').strip()
            if task['type'] == 'float':
                res.append(float(ret))
            else:
                res.append(int(ret))
        mm, ma, med, mea, drv = min(res), max(res), statistics.median(res), statistics.mean(res), statistics.pstdev(res)

        print("[Partial]Result: min({}), max({}), medium:({}), mean({}), drv({})".format(mm, ma, med, mea, drv))
        trial.append(mea)

    print("Result: avg({}), drv({})".format(statistics.mean(trial), statistics.pstdev(trial)))
    # Save result if necessary
    with open(write_result, 'w') as f:
        json.dump(trial, f)

'''
Basic idea: each exec should only giving a number out, python exec it and get the number.
repeat some time and get the result, persist into a txt, and plot them. 
'''

'''
CPU Affinity: use `taskset --cpu-list 30 "command"` to force it. Save some time coding it yourself :)
'''