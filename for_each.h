// --------
// for_each
// --------

#ifndef for_each_h
#define for_each_h

#include <functional>



//Requirements: 
// InputIterator: ++, *(read), *(write), but I don't think the write is correct for an II
template<class InputIterator, class function>
function for_each(InputIterator b, InputIterator e, function f){
    while(b != e){
        f(*b);
        ++b;
    }
    return f;
}



#endif
