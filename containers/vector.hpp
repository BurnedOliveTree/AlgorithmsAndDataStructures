#ifndef ads_vector_hpp
#define ads_vector_hpp

#include <ostream>
#include <sstream>

#include "container.hpp"

namespace ads {
    template <class T>
    class Vector: public Container<T> {
        void changeDataSize(bool increase) {
        /// increases or decreases the maximum amount of elements
            if (increase)
                _max_size *= 2;
            else
                _max_size /= 2;
            T* temp = new T[_max_size];
            for (int i=0; i<_size; ++i)
                temp[i] = _data[i];
            delete[] _data;
            _data = temp;
        }
        void moveData() {
        /// moves all the elements by 1 space
            for (int i=1; i<_size; ++i)
                _data[i-1] = _data[i];
        }
    protected:
        unsigned long _size;
        unsigned long _max_size;
        T* _data;
    public:
        Vector() {
            _size = 0;
            _max_size = 1;
            _data = new T[1];
        };
        ~Vector() {
            delete[] _data;
        };
        unsigned long size() const {
        /// returns amount of elements in vector
            return _size;
        }
        bool empty() const {
        /// returns true if there aren't any elements in vector
            if (_size == 0)
                return true;
            else
                return false;
        }
        bool compare(const Vector<T>& myVector) const {
        /// compares this vector's content with another given vector
            if (this->_size != myVector._size)
                return false;
            for (int i=0; i<this->_size; ++i)
                if (this->_data[i] != myVector._data[i])
                    return false;
            return true;
        }
        T& at(unsigned long index) const {
        /// returns a reference to a desired element of the vector
            if (index < 0 or index >= _size) {
                std::ostringstream error_msg;
                error_msg << "called at(" << index << ") on a vector of size " << _size;
                throw std::out_of_range(error_msg.str());
            }
            return _data[index];
        }
        T& front() const {
        /// returns a reference to the first element of the vector
            return _data[0];
        }
        T& back() const {
        /// returns a reference to the last element of the vector
            return _data[_size-1];
        }
        void push_back(T new_element) {
        /// adds an element at the end of the vector
            if (_size == _max_size)
                changeDataSize(1);
            _data[_size] = new_element;
            _size++;
        }
        T pop_front() {
        /// returns and removes the first element of the vector
            if (empty())
                throw std::out_of_range("called pop() when vector is empty");
            T temp = _data[0];
            moveData();
            _size--;
            if (_size == _max_size/2)
                changeDataSize(0);
            return temp;
        }
        T pop_back() {
        /// returns and removes the last element of the vector
            if (empty())
                throw std::out_of_range("called pop_back() when vector is empty");
            T temp = _data[_size-1];
            _size--;
            if (_size == _max_size/2)
                changeDataSize(0);
            return temp;
        }
        T& operator[](unsigned long index) const {
            return this->at(index);
        }
        bool operator== (const Vector<T>& myVector) const {
            return this->compare(myVector);
        }
        bool operator!= (const Vector<T>& myVector) const {
            return !this->compare(myVector);
        }
        friend std::ostream& operator<< (std::ostream& myStream, const Vector<T>& myVector) {
            for (int i=0; i<myVector._size; ++i)
                myStream << myVector._data[i] << ", ";
            return myStream;
        }
    };
};

#endif /* ads_vector_hpp */
