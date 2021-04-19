#ifndef ads_vector_hpp
#define ads_vector_hpp

#include <ostream>

namespace ads {
    template <class T>
    class Vector {
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
    public:
        Vector() {
            _size = 0;
            _max_size = 1;
            data = new T[1];
        };
        ~Vector() {
            delete[] data;
        };
        unsigned long size() {
        /// returns amount of elements in vector
            return _size;
        }
        bool isEmpty() {
        /// returns true if there aren't any elements in vector
            if (_size == 0)
                return true;
            else
                return false;
        }
        void push_back(T new_element) {
        /// adds an element at the end of the vector
            if (_size == _max_size)
                changeDataSize(1);
            data[_size] = new_element;
            _size++;
        }
        T pop() {
        /// returns and removes the first element of the vector
            if (isEmpty())
                throw std::out_of_range("called pop() when vector is empty");
            T temp = data[0];
            moveData();
            _size--;
            if (_size == _max_size/2)
                changeDataSize(0);
            return temp;
        }
        T pop_back() {
        /// returns and removes the last element of the vector
            if (isEmpty())
                throw std::out_of_range("called pop_back() when vector is empty");
            T temp = data[_size-1];
            _size--;
            if (_size == _max_size/2)
                changeDataSize(0);
            return temp;
        }
        T& operator[](unsigned long index)
        {
            return data[index];
        }
        bool operator== (const Vector<T>& myVector) {
            if (this->_size != myVector._size)
                return false;
            for (int i=0; i<this->_size; ++i)
                if (this->data[i] != myVector.data[i])
                    return false;
            return true;
        }
        bool operator!= (const Vector<T>& myVector) {
            if (this->_size != myVector._size)
                return true;
            for (int i=0; i<this->_size; ++i)
                if (this->data[i] != myVector.data[i])
                    return true;
            return false;
        }
        friend std::ostream& operator<< (std::ostream& myStream, const Vector<T>& myVector) {
            for (int i=0; i<myVector._size; ++i)
                myStream << myVector.data[i] << ", ";
            return myStream;
        }
    };
};

#endif /* ads_vector_hpp */
