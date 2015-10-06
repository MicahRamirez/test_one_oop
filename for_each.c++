#include "gtest/gtest.h"
#include <list>
#include <vector>
#include <functional>
#include "for_each.h"

using namespace std;

TEST(ForeachFixture, test_1){
	int tmp[] = {1, 3, 5, 7};
	//vector c containing 1,3,5,7
	vector<int> c(tmp, tmp + sizeof(tmp) / sizeof(int));
	for_each(c.begin(), c.end(), [](int &x){return (x)*2;});
	ASSERT_EQ(c[0], 2);
}