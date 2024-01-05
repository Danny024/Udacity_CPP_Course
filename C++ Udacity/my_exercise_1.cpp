#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

const int array_size = 1e6; // determines the size of the random number array
vector <int> *RandomNumbers1(){
    vector<int> *random_numbers = new vector <int> (array_size);
    for (int i = 0; i < array_size; i++){
        int b = rand ();
        (*random_numbers).push_back(b);

    }
    return random_numbers;
}

void RandomNumbers2 (vector<int> &random_numbers)
{
    random_numbers.resize(array_size);
    for (int i = 0; i < array_size; i++){
        random_numbers[i] = rand();
    }
}

int main (){
    //solution to exercise 1-1
   vector <int> *random_numbers_1 = RandomNumbers1();
   delete random_numbers_1;

   // solution to exercise 1-2
   vector<int> random_numbers_2;
   RandomNumbers2 (random_numbers_2);
}


