#ifndef ads_heapsdontlie_hpp
#define ads_heapsdontlie_hpp

#include "../math.hpp"
#include "vector.hpp"

namespace ads {
    template <class T>
    class Heap {
        Vector<T> _data;
        unsigned long _size;
        unsigned long _child_amount;  // amount of direct children in a single node
    public:
        Heap(unsigned long child_amount) {
            _size = 0;
            _child_amount = child_amount;
        }
        void append(T value) {
            unsigned long i = _size;
            _size += 1;
            _data.push_back(value);
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
        friend std::ostream& operator<< (std::ostream& myStream, const Heap<T>& myHeap) {
            for (unsigned long i=0; i<myHeap._size; ++i)
                myStream << myHeap._data[i] << ", ";
            return myStream;
        }
    };
}


#endif /* ads_heapsdontlie_hpp */