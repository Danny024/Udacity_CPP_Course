#include <chrono>
#include <iostream>

// C++ uses a row major address system
// Memory aware programmer ....
// Spatial Locality and Temporal Locality;


int main()
{
    // create array 
    const int size = 4000;
    static int x[size][size];

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            x[i][j] = i + j;
            //std::cout << &x[i][j] << ": i=" << i << ", j=" << j << std::endl;
        }
    }

    // print execution time to console
    auto t2 = std::chrono::high_resolution_clock::now(); // stop time measurement
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution time: " << duration << " microseconds" << std::endl;

    return 0;
}