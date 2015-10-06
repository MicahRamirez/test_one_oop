// --------
// for_each
// --------

#ifndef for_each_h
#define for_each_h



//Requirements: 
// InputIterator: ++, *(read), *(write), but I don't think the write is correct for an II
template<class InputIterator, class UnaryFunction>
UnaryFunction for_each(InputIterator b, InputIterator e, UnaryFunction f){
    while(b != e){
        *b = f(b);
        b++;
    }
}

#endif
