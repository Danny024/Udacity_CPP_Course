#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// Define Constructor
Process::Process (const int pid) : _pid(pid), _username (LinuxParser::User(pid)),_cmd (LinuxParser::Command(pid)), _cpu_util(Process::CpuUtilization()) {}

// TODO: Return this process's ID
int Process::Pid() { 
    return _pid; 
    }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    long int frequency = sysconf (_SC_CLK_TCK);
    const long active_time = LinuxParser :: ActiveJiffies (_pid) / frequency;
    const long total_uptime = LinuxParser::UpTime (_pid);
    _cpu_util = (active_time / total_uptime * 1.0);
    return _cpu_util;
    
    }

// TODO: Return the command that generated this process
string Process::Command() { 
    return _cmd; 
    
    }

// TODO: Return this process's memory utilization
string Process::Ram() { 
    return LinuxParser::Ram (_pid); 
    }

// TODO: Return the user (name) that generated this process
string Process::User() { 
    return _username; 
    }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
    return LinuxParser::UpTime(_pid); 
    
    }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return (this->_cpu_util > a._cpu_util); 
    
    
    }