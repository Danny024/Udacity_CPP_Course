#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;
using std::move;
/*You need to complete the mentioned TODOs in order to satisfy the rubric criteria "The student will be able to extract and display basic data about the system."

You need to properly format the uptime. Refer to the comments mentioned in format. cpp for formatting the uptime.*/
// Define Constructor
System::System (): _OS (LinuxParser::OperatingSystem()), _Kernel_Version (LinuxParser::Kernel()){}
// TODO: Return the system's CPU
Processor& System::Cpu() { return _cpu; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    _processes = {};
    vector <int> process_id = LinuxParser::Pids();
    for (int id : process_id){
        Process process (id);
        _processes.emplace_back(move(process));
    }
    sort (_processes.begin(), _processes.end());
    return _processes; 
    
    
    }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { 
    return _Kernel_Version; 
    
    }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization(); 
    
    }

// TODO: Return the operating system name
std::string System::OperatingSystem() { 
    return _OS; 
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { 
    return LinuxParser::RunningProcesses(); 
    
    }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { 
    return LinuxParser::TotalProcesses(); 
    }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { 
    return LinuxParser::UpTime(); 
    }
