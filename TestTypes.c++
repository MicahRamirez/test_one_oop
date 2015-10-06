#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "types.h"

using namespace std;

//Observations
/*
*What is the difference between int j = i; and int& j = i;  ?
*/

//passing j by reference
TEST(ChangeFixture, f_change_1){
		//init i to zero
		int i = 0;
		//j is a pointer to i
		int& j = i;
		//call f_change
		f_change(j);
		ASSERT_EQ(1, i);
		//j and i should be references to the same thing in mem
		ASSERT_EQ(j, i);
}

//passing j BY REFERENCE
TEST(ChangeFixture, f_change_2){
	int i = 0;
	int& j =i;
	f_change(j);
	f_change(j);
	//variable i should have been incremented twice
	ASSERT_EQ(2,i);
}

//Passing J by VALUE
TEST(ChangeFixture, f_change_val_1){
	int i = 0;
	//j is a reference to i
	int& j = i;
	//passing a reference to i by value
	f_change_val(j);
	f_change_val(j);
	//since we are passing by value, the changes to j which points to i
	//are local to the method. Therefore, no change. Both i and j are zero
	ASSERT_EQ(0, j);
	ASSERT_EQ(0, i);
}

TEST(ChangeFixture, f_change_val_2){
	int i = 0;
	//j is a reference to i 'alias'
	int& j = i;
	f_change_val(j);
	//j is a reference to i
	//I think we'd need to dereference this for this to be equal
	//expect a fail
	ASSERT_EQ(0, j);
	ASSERT_EQ(0, i);
}

TEST(ChangeFixture, f_change_pointer_1){
	int i = 0;
	int* j = &i;
	f_change_pointer(j);

	//j points to i, dereferrence the pointer to get the val of i
	//which should be 1
	ASSERT_EQ(1, *j);
	//i which was passed by pointer should be incremented
	ASSERT_EQ(1, i);

	//the value of i should be the same as something pointing to i dereffed
	ASSERT_EQ(i, *j);
}

TEST(ChangeFixture, f_change_pointer_2){
	int i = 0;
	int* j = &i;
	int* k = &i;
	//Since the method is expecting a pointer,
	//this will not compile since you cannot convert int to int*
	//int* j = i;
	//f_change_pointer(int* j);
	f_change_pointer(j);
	ASSERT_EQ(*j, 1);
	f_change_pointer(k);
	//i is equal to 2 at this point
	ASSERT_EQ(i, 2);
	//they both equal i's current value
	ASSERT_EQ(*j, *k);

	//they are both pointing to i which is &i
	ASSERT_EQ(j, k);

	//they are not the same pointer in memory
	ASSERT_NE(&j, &k);
}