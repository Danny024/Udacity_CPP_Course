#include <string>

#include "format.h"

using std::string;
using std::to_string;
// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long int seconds) { 
    long int HH {seconds / 3600},HH_rem {seconds % 3600},MM{HH_rem / 60}, SS{HH_rem % 60};
     // Covert parameters to string
     string string_HH {to_string(HH)};
     string string_MM {to_string(MM)};
     string string_SS {to_string(SS)};
    return (string_HH + ':'+string_MM +':'+ string_SS);
    }