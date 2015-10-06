#include <cassert>
#include <list>
#include <iostream>
#include <functional>

#include "gtest/gtest.h"
#include "gtest/gtest_prod.h"
#include "types.h"

using namespace std;

//by reference
void f_change(int& j){
	j++;
}

//by value
void f_change_val(int j){
	j++;
}

//by reference, pointer in this case
void f_change_pointer(int* j){
	(*j)++;
}