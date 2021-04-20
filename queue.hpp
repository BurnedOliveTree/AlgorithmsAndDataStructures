#ifndef ads_fifoqueue_hpp
#define ads_fifoqueue_hpp

#include "vector.hpp"

namespace ads {
    template <class T>
    class Queue: public Vector<T> {
    private:
        /// makes at private since user should not be able to access random elements of queue
        using Vector<T>::at;
        using Vector<T>::operator[];
        /// makes pop_back private since it's a fifo queue
        using Vector<T>::pop_back;
    };
}

#endif /* ads_fifoqueue_hpp */
