#ifndef ads_heapsdontlie_hpp
#define ads_heapsdontlie_hpp

#include "../algorithms/math.hpp"
#include "vector.hpp"

namespace ads {
    template <class T>
    class Heap: public Vector<T> {
        using Vector<T>::_data;
        using Vector<T>::_size;
        unsigned long _child_amount;  // amount of direct children in a single node
        Heap() {}
        using Vector<T>::insert;
        using Vector<T>::push_front;
        using Vector<T>::pop_front;
        using Vector<T>::pop_back;
    public:
        Heap(unsigned long child_amount) {
            _size = 0;
            _child_amount = child_amount;
        }
        void push_back(T new_element) {
            unsigned long i = _size;
            Vector<T>::push_back(new_element);
            while (i > 0 && _data[i] < _data[i / _child_amount]) {
                swap(_data[i], _data[i / _child_amount]);
                i = i / _child_amount;
            }
        }
        void heapify(unsigned long index) {
            for (unsigned long i = 0; i < _child_amount; ++i)
                if (_child_amount * index + _child_amount - i < _size)
                    if (_data[_child_amount*index+_child_amount-i] < _data[index])
                    {
                        swap(_data[_child_amount * index + _child_amount - i], _data[index]);
                        heapify(_child_amount * index + _child_amount - i);
                    }
        }
        bool check(unsigned long index=0) const {
            for (unsigned long i = 0; i < _child_amount; ++i)
                if (_child_amount * index + _child_amount - i < _size) {
                    if (_child_amount * index + _child_amount - i < _data[index])
                        return false;
                    else
                        return check(_child_amount * index + _child_amount - i);
                }
                else
                    return true;
        }
    };
}


#endif /* ads_heapsdontlie_hpp */