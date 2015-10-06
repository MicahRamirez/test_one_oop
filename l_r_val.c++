//lvalue - an obj that occupies some id-able loc in *memory*
//rvalue - any obj that is not an lval

class dog{};

int cube(const int& i){
    return i*i*i;
}

int main(){


/**
*lval examples
*/
int i; //i is an l value
int *p = &i;  //can id i's address
i = 2;

dog d1;   //lval of user def'ed type

/**
*rval examples
*/

int x = 5; 
x = i + 10;
//int* p = &(i+2);  ERROR
//i+10;             ERROR
//100 = i;          ERROR


/**
*lval reference
*/

int j;
int& m = j;
//int& j = 5;       ERROR
//cannot assign an lval to an rval

//There exists an exception to this
//A constant lvalue can be assigned an rvalue
const int& k = 5;
cube(m);
cube(400);

int arr[2];
*(arr+1) = 2;

return 0;
}

//misconceptions

/*
* function or operators always yields rvalues
* ASIDE: Operator [] almost always generates an lvalue
*
*lvalues are modifiable
*   Counterexample => const int c = 1; ... c = 2; ERROR!
*
*rvalues are not modifiable
* ! Only true for built in types
*     Not necessarily true for user defined types (classes)
*/
