#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

void func() {
    
    std::vector<const char*> arr1;
    std::vector<std::string> arr2;
    std::vector<std::string> tmp = { "a", "b", "c" };

    for (std::string &el: tmp) {
        std::string test = el + std::string("!");
        arr1.push_back(test.c_str());       
        arr2.push_back(test);
    }

    for (unsigned int i= 0; i < arr1.size(); i++)
    {
        printf("curval arr1: %s\n", arr1[i]);            // prints c! c! c!
        printf("curval arr2: %s\n", arr2[i].c_str());    // prints a! b! c!
    }

    /**
     * 
     * Why does the printf iteration of arr1 print c! three times?
     * 
     * Analysis:
     *  - arr1 stores raw pointers
     *  - c_str() returns a const char * value of the string 
     *  - this value is pushed into the array, however its lifecycle is only valid in the scope of the for loop
     *  - thus, once the iteration proceeds, the previous pointer stored in arr1 is destroyed (dangling pointer)
     *  - as a result, at the end of the loop, arr1 holds two dangling pointers pointing to invalid memory, and one valid pointer pointing to the value of the last string
     * 
     * Further Analysis: 
     *  - Then why does it end up to print c! three times? shouldn't it print garbage value?
     *  - UB (undefined Behavior)
     *  - however, it has to do with std::string and its behavior of managing internal memory 
     *  - std::string and memory reuse
     *      - std::string dynamically allocates memory
     *      - after every iteration, it is expected for the string memory to be freed and reallocated
     *      - however, std::string reuses memory, meaning it occupies the same memory location
     */ 

}

int main(void)
{
    func();
    return 0;    
}

