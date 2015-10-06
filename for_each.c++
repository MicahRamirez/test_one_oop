#include "gtest/gtest.h"
#include <vector>
#include <functional>
#include "for_each.h"

using namespace std;

TEST(ForeachFixture, test_1){
	int tmp[] = {1, 3, 5, 7};
	//vector c containing 1,3,5,7
	vector<int> c(tmp, tmp + sizeof(tmp) / sizeof(int));
	for_each(c.begin(), c.end(), [](int &x){x = (x)*2;});
	ASSERT_EQ(c[0], 2);
}

TEST(ForeachFixture, test_2){
	vector<int> test2 {2, 6, 9};
	for_each(test2.begin(), test2.end(), [](int& x){++x;});
	ASSERT_EQ(test2[0], 3);
	ASSERT_EQ(test2[1], 7);
	ASSERT_EQ(test2[2], 10);
}

TEST(ForeachFixture, test_3){
	vector<int> test3 {-1, -5, 0};
	for_each(test3.begin(), test3.end(), [](int& x){++x;});
	ASSERT_EQ(test3[0], 0);
	ASSERT_EQ(test3[1], -4);
	ASSERT_EQ(test3[2], 1);
}