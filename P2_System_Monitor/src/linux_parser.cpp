#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "linux_parser.h"

using std::stof;
using std::stol;
using std::string;
using std::to_string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::replace;
using std::cout;
using std::endl;


// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  long Total_Memory {}, Free_Memory {};
  ifstream file_path (LinuxParser::kProcDirectory + LinuxParser::kMeminfoFilename);
  
  if(file_path.is_open()){
    string mem_label, mem_value, unit, line;
    while (getline (file_path,line)){
      istringstream line_stream (line);
        line_stream >> mem_label;
        if (mem_label=="MemTotal:"){
          line_stream >> Total_Memory;
        }

        else if (mem_label == "MemFree:"){
          line_stream >> Free_Memory;
        }
      
    }
     if (Total_Memory > 0){
       return static_cast <float> (Total_Memory - Free_Memory) / Total_Memory;
     }
  }

  return 0.0f;

  
  }

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  string idle_time, up_time, line;
  long int system_uptime;

  ifstream file_stream (LinuxParser::kProcDirectory + LinuxParser::kUptimeFilename);
  if (file_stream.is_open()){
    getline (file_stream,line);
    istringstream line_stream (line);
    line_stream >> up_time >> idle_time;
    system_uptime = stol(up_time);
  }
  return system_uptime;
  
  }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {
   
  string jiffy, line;
  long clock {};
  vector<string> stats;
  int start_string {13}, end_string {16};


  ifstream file_path (LinuxParser::kProcDirectory + to_string (pid) + LinuxParser::kStatFilename);
  if (file_path.is_open()){
      getline (file_path,line);
      istringstream line_stream (line);
      while (line_stream >> jiffy){
        stats.emplace_back (jiffy);
      }
  }

  for (int i = start_string; i <= end_string; ++i){
    /*
    stats [13] = utime;
    stats [14] = stime;
    stats [15] = cutime;
    stats [16] = cstime
    clock = utime + stime + cutime + cstime;
    */

    clock += stol(stats[i]) / sysconf(_SC_CLK_TCK); 
  }
  

  return clock; 
  
  }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
  long active_jiffies;
  int stop {8};
  int idle {3}, iowait {4};

  for (int key = 0; key < stop; ++key){
    if (key != idle && key != iowait ){
      active_jiffies += stoi(LinuxParser::CpuUtilization()[key]);
    }
  }

  return active_jiffies;
  
  }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
  int idle {3}, iowait {4};
  string idle_string;
  string iowait_string;
  idle_string = LinuxParser::CpuUtilization()[idle];
  iowait_string = LinuxParser::CpuUtilization () [iowait];
  return (stol(idle_string) + stol(iowait_string));
  
  }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 
string token, line;
vector<string> cpu_Utilization;
  
ifstream file_path (LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  
  if (file_path.is_open()){
    getline (file_path, line);
    istringstream line_stream (line);
    while (line_stream >> token ){
      if (token != "cpu"){
        cpu_Utilization.emplace_back (token);
      }
    }
  }
  return cpu_Utilization; 


}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
  string labels, num_processes;
  string line;
  int numprocesses_int {};
  ifstream file_path (LinuxParser::kProcDirectory + LinuxParser::kStatFilename);

  if (file_path.is_open()){
    while (getline (file_path, line)){
      istringstream line_stream (line);
      while (line_stream >> labels >> num_processes){
        if (labels == "processes"){
          numprocesses_int = stoi (num_processes);
          return numprocesses_int;
        }
      }

    }
    
  }
  
  return 0; 

}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  string label, value,line;
  ifstream file_path (LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (file_path.is_open()){
    while (getline (file_path, line)){
      istringstream linestream (line);
      while (linestream >> label >> value){
        if (label == "procs_running"){
          return stoi (value);
        }

      }

    }
    
  }
  
  return 0; 
  
  
  }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
  string command {"No command found!"}, line;
  ifstream file_path (LinuxParser::kProcDirectory + to_string(pid) + LinuxParser::kCmdlineFilename);
  if (file_path.is_open()){
    if (getline (file_path,line)){
      command = line;

    }


  }

  return command; 
  }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) { 
  string line;
  string pid_string {to_string(pid)};
  string label, size,ram;
  ifstream file_path (LinuxParser::kProcDirectory + pid_string + LinuxParser::kStatusFilename);
  if (file_path.is_open()){
    while (getline(file_path, line)){
      istringstream line_stream (line);
      while (line_stream >> label >> size){
        if (label == "VmSize:"){
          ram = to_string (stof(size)/ 1000.0);
          return ram;

        }
      }
    }

  }
  return ram; 
  
  }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) { 
  string pid_string {to_string(pid)};
  string label, user_id, line;
  
  ifstream file_path (LinuxParser::kProcDirectory + pid_string + LinuxParser::kStatusFilename);
  if (file_path.is_open()){
    while (getline (file_path, line)){
      istringstream line_stream (line);
      while (line_stream >> label >> user_id){
        if (label =="Uid:"){
          return user_id;
        }
      }
    }
  }
  return 0; 
  
  }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
  string user_id = LinuxParser::Uid (pid);
  string line, user, domain, id;

  ifstream file_path (LinuxParser::kPasswordPath);
  if (file_path.is_open()){
    while (getline (file_path, line)){
      replace (line.begin(), line.end(), ':', ' ');
      istringstream line_stream (line);
      while (line_stream >> user >> domain >> id){
        if (id == user_id){
          return user;
        }
      }
    }
  }

  return 0; 
  
  
  }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  string pid_string {to_string (pid)}, line, dummy;
  int index_start_time {21};
   long uptime;
   vector <string> stats;

   ifstream file_path (LinuxParser::kProcDirectory + pid_string + LinuxParser::kStatFilename);
   if (file_path.is_open()){
     getline (file_path, line);
     istringstream line_stream (line);
     for (int i = 0; i<index_start_time; ++i ){
       line_stream >> dummy;
     }
     line_stream >> uptime;
     file_path.close();
   }
   return uptime;

  
  }
