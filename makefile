FILES :=							\
	for_each.h						\
	for_each.c++

CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f for_each
	rm -f for_each.tmp

test_for_each: for_each.tmp

for_each.tmp: for_each
	$(VALGRIND) ./for_each > for_each.tmp 2>&1
	$(GCOV) -b for_each.c++ | grep -A "File 'for_each.c++'" >> for_each.tmp
	cat for_each.tmp

for_each: for_each.h for_each.c++ 
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) for_each.c++ -o for_each $(LDFLAGS)