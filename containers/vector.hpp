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
            for (unsigned long i=0; i<_size; ++i)
                temp[i] = _data[i];
            delete[] _data;
            _data = temp;
        }
        void moveData(unsigned long index = 0, bool ascending = true) {
        /// moves all the elements by 1 space
            if (ascending)
                for (unsigned long i=index+1; i<_size; ++i)
                    _data[i-1] = _data[i];
            else
                if (_size > 0)
                    for (unsigned long i=_size; i>index; --i)
                        _data[i] = _data[i-1];
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
            for (unsigned long i=0; i<this->_size; ++i)
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
        void insert(T new_element, unsigned long index) {
        /// inserts an element at the given index in the vector
            if (_size == _max_size)
                changeDataSize(1);
            moveData(index, false);
            _data[index] = new_element;
            _size++;
        }
        void push_front(T new_element) {
        /// adds an element at the start of the vector
            this->insert(new_element, 0);
        }
        void push_back(T new_element) {
        /// adds an element at the end of the vector
            this->insert(new_element, _size);
        }
        T erase(unsigned long index) {
        /// returns and removes the element from a given index of the vector
            if (empty())
                throw std::out_of_range("called erase() when vector is empty");
            T temp = _data[index];
            moveData(index);
            _size--;
            if (_size == _max_size/2)
                changeDataSize(0);
            return temp;
        }
        T pop_front() {
        /// returns and removes the first element of the vector
            return this->erase(0);
        }
        T pop_back() {
        /// returns and removes the last element of the vector
            return this->erase(_size-1);
        }
        void clear() {
        /// erases all elements from the vector
            for (unsigned long i = _size - 1; i > 0; --i)
                this->erase(i);
            this->erase(0);
        }
        void assign(T carray[], unsigned long carray_size, unsigned long index=0) {
        /// assign content of an C array to this vector
            for (unsigned long i = 0; i < carray_size; ++i) {
                this->insert(carray[i], index+i);
            }
        }
        void assign(T value, unsigned long amount, unsigned long index=0) {
        /// assign *amount* of *value* to this vector
            for (unsigned long i = 0; i < amount; ++i) {
                this->insert(value, index);
            }
        }
        T& operator[](unsigned long index) const {
            return this->at(index);
        }
        void operator= (const List<T>& myList) const {
            return this->assign(myList);
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
