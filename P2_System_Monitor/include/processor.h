#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor ();
  float Utilization();  // TODO: See src/processor.cpp
  
  // TODO: Declare any necessary private members
 private:
  long _idle_prev_jiffies, _active_prev_jiffies, _prev_jiffies;
  float _usage {};
};

#endif