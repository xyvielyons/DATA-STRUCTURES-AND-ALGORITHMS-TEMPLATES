//recursion = a programming technique where a function invokes itself from within
//break a complex concept into repeatable single step
#include <iostream>
#include <string>

//iterative approach
void walk(int steps){
    for (int i = 0; i < steps; i++)
    {
        std::cout << "You take a steps" << std::endl;
    }
    
};

int factorial(int num){
    int result = 1;
    for (int i = 1; i <= num; i++)
    {
        result = result * i; 
    }
    return result;

}





//recursive approach
// it uses more memory and processing time because it is a function within a function
//recursion invokes itself from within
void walkrecursive(int steps){
    //when we remove steps > 0 if we end up with an infinite loop(stack overflow)
    if(steps > 0)
    {
        std::cout << "You take a stepx" << std::endl;
        //i will invalk the walkrecursive from within itself
        walkrecursive(steps-1);
    }
    
};

int factorialrecursive(int num){
    if(num > 1){
        return num * factorialrecursive(num-1);
    }else{
        return 1;
    }

} 



int main(){
    //walk(100);
    walkrecursive(100);
    std::cout <<"factorial:" << factorial(10) << std::endl;
    std::cout <<"factorialrecursive:" << factorialrecursive(10) << std::endl;
    return 0;
}
