#include "processor.h"
#include "linux_parser.h"
// TODO: Return the aggregate CPU utilization
// Constructor 
Processor :: Processor () : _idle_prev_jiffies (LinuxParser::IdleJiffies()), _active_prev_jiffies (LinuxParser::ActiveJiffies()), _prev_jiffies(_active_prev_jiffies + _idle_prev_jiffies) {}

float Processor::Utilization() { 
    const long idle_current_jiffies = LinuxParser::IdleJiffies();
    const long active_current_jiffies = LinuxParser::ActiveJiffies();
    const long current_jiffies = idle_current_jiffies + active_current_jiffies;

    const long diff_idle_jiffies = idle_current_jiffies - _idle_prev_jiffies;
    const long diff_jiffies = current_jiffies - _prev_jiffies;

    _idle_prev_jiffies = idle_current_jiffies;
    _active_prev_jiffies = active_current_jiffies;
    _prev_jiffies = current_jiffies;

    _usage = diff_jiffies == 0? 0.0f : (diff_jiffies - diff_idle_jiffies) * 1.0 / diff_jiffies;
    return _usage;
    }