#ifndef types_h
#define types_h
#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "gtest/gtest_prod.h"

using namespace std;


void f_change(int& j);

void f_change_val(int j);
void f_change_pointer(int* j);
#endif