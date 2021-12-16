#!/bin/bash

# Pick this up from lscpu or derive it from msrs.
CPU_FREQ=2000000 # Only at this hz the cpu is stable, maybe it is just too old to be that high...

# SET BOTH CPU TO CONST FRQ
for i in $(ls /sys/devices/system/cpu/cpu*/cpufreq/scaling_max_freq); do echo "${CPU_FREQ}" | sudo tee $i > /dev/null 2>&1 ;done
for i in $(ls /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq); do echo "${CPU_FREQ}" | sudo tee $i > /dev/null 2>&1 ;done

# TURN OFF C CSTATE
for i in $(ls /sys/devices/system/cpu/cpu*/cpuidle/state*/disable); do echo "1" | sudo tee $i > /dev/null 2>&1 ;done

# NO TURBO
sudo modprobe msr
sudo wrmsr -a 0x1a0 $(printf "0x%x" $(($(sudo rdmsr -d 0x1a0)|(1<<38))))


# PRINT RESULT
for i in $(ls /sys/devices/system/cpu/cpu*/cpufreq/scaling_max_freq); do echo "$i: $(cat $i)";done
for i in $(ls /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq); do echo "$i: $(cat $i)";done
for i in $(ls /sys/devices/system/cpu/cpu*/cpuidle/state*/disable); do echo "$i: $(cat $i)";done
sudo rdmsr -a 0x1a0 -f 38:38


# watch -n.1 grep MHz /proc/cpuinfo