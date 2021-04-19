#ifndef fifoqueue_hpp
#define fifoqueue_hpp

namespace ads {
    template <class T>
    class queue {
        unsigned long _size;
        unsigned long _max_size;
        T* data;
        
        void changeDataSize(bool increase) {
        /// increases or decreases the maximum amount of elements
            if (increase)
                _max_size *= 2;
            else
                _max_size /= 2;
            T* temp = new T[_max_size];
            for (int i=0; i<_size; ++i)
                temp[i] = data[i];
            delete[] data;
            data = temp;
        }
        void moveData() {
        /// moves all the elements by 1 space
            for (int i=1; i<_size; ++i)
                data[i-1] = data[i];
        }
        T& operator[](unsigned long index)
        /// makes [] operator private since user should not be able to access random elements of queue
        {
            return data[index];
        }
    public:
        queue() {
            _size = 0;
            _max_size = 1;
            data = new T[1];
        };
        ~queue() {
            delete[] data;
        };
        unsigned long size() {
        /// returns amount of elements in queue
            return _size;
        }
        bool isEmpty() {
        /// returns true if there aren't any elements in queue
            if (_size == 0)
                return true;
            else
                return false;
        }
        void push(T new_element) {
        /// adds an element at the end of the queue
            if (_size == _max_size)
                changeDataSize(1);
            data[_size] = new_element;
            _size++;
        }
        T pop() {
        /// returns and removes the first element of the queue
            if (isEmpty())
                throw std::out_of_range("called pop() when queue is empty");
            T temp = data[0];
            moveData();
            _size--;
            if (_size == _max_size/2)
                changeDataSize(0);
            return temp;
        }
        bool operator== (const queue<T>& myQueue) {
            if (this->_size != myQueue._size)
                return false;
            for (int i=0; i<this->_size; ++i)
                if (this->data[i] != myQueue.data[i])
                    return false;
            return true;
        }
        bool operator!= (const queue<T>& myQueue) {
            if (this->_size != myQueue._size)
                return true;
            for (int i=0; i<this->_size; ++i)
                if (this->data[i] != myQueue.data[i])
                    return true;
            return false;
        }
        friend std::ostream& operator<< (std::ostream& myStream, const queue<T>& myQueue) {
            for (int i=0; i<myQueue._size; ++i)
                myStream << myQueue.data[i] << ", ";
            return myStream;
        }
    };
}

#endif /* fifoqueue_hpp */
