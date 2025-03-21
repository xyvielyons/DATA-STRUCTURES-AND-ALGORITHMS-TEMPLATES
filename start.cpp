#include <iostream>
#include <string>

struct point {
    int x;
    std::string y;
    struct point *ptr;
};



int main(){
    struct point point1;
    struct point point2;

    point1.x=65;
    point1.y = "pointone";
    point1.ptr = NULL;

    point2.x=100;
    point2.y = "pointtwo";
    point2.ptr = NULL;

    point1.ptr = &point2;

    std::cout << point1.ptr->y << std::endl;


    return 0;
};
