#ifndef ads_list_hpp
#define ads_list_hpp

#include <sstream>
#include <ostream>

#include "container.hpp"

namespace ads {
    template <class T>
    class List: public Container<T> {
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(T arg_data, Node* arg_next, Node* arg_prev) {
                data = arg_data;
                next = arg_next;
                prev = arg_prev;
            }
        };

        unsigned long _size;
        Node* _head;
        Node* _tail;
    public:
        List() {
            _size = 0;
            _head = nullptr;
            _tail = nullptr;
        };
        ~List() {
            Node* node = this->_head;
            if (node) {
                while (node->next) {
                    node = node->next;
                    delete node->prev;
                }
                delete node;
            }
        };
        unsigned long size() const {
        /// returns amount of elements in list
            return _size;
        }
        bool empty() const {
        /// returns true if there aren't any elements in list
            if (_size == 0)
                return true;
            else
                return false;
        }
        bool compare(const List<T>& myList) const {
        /// compares this list's content with another given list
            if (this->_size != myList._size)
                return false;
            Node* this_node = this->_head;
            Node* his_node = myList._head;
            for (unsigned long i=0; i<this->_size; ++i) {
                if (this_node->data != his_node->data)
                    return false;
                this_node = this_node->next;
                his_node = his_node->next;
            }
            return true;
        }
        T& at(unsigned long index) const {
        /// returns a reference to a desired element of the list
            if (index < 0 || index >= _size) {
                std::ostringstream error_msg;
                error_msg << "called at(" << index << ") on a list of size " << _size;
                throw std::out_of_range(error_msg.str());
            }
            Node* elem = this->_head;
            for (unsigned long i = 0; i < index; ++i) {
                elem = elem->next;
            }
            return elem->data;
        }
        List<T> sub(unsigned long start, unsigned long end) const {
        /// returns a sublist of a desired range of elements
            if (start >= _size or end >= _size or start > end) {
                std::ostringstream error_msg;
                error_msg << "called sub(" << start << ", " << end << ") on a list of size " << _size;
                throw std::out_of_range(error_msg.str());
            }
            List<T> result;
            for (unsigned long i = start; i < end; ++i)
                result.push_back(this->at(i));
            return result;
        }
        T& front() const {
        /// returns a reference to the first element of the list
            return _head->data;
        }
        T& back() const {
        /// returns a reference to the last element of the list
            return _tail->data;
        }
        void insert(T new_element, unsigned long index) {
        /// inserts an element at the given index of the list
            if (index < 0 || index > _size) {
                std::ostringstream error_msg;
                error_msg << "called insert(" << index << ") on a list of size " << _size;
                throw std::out_of_range(error_msg.str());
            }
            if (_size == 0) {
                this->_head = new Node(new_element, nullptr, nullptr);
                this->_tail = this->_head;
                _size++;
                return;
            }
            else {
                Node* elem = this->_head;
                Node* prev_elem = nullptr;
                for (unsigned long i = 0; i < index; ++i) {
                    prev_elem = elem;
                    elem = elem->next;
                }
                Node* new_node = new Node(new_element, elem, prev_elem);
                if (index == 0)
                    _head = new_node;
                else
                    prev_elem->next = new_node;
                if (index == _size)
                    _tail = new_node;
                else
                    elem->prev = new_node;
                _size++;
            }
        }
        void push_front(T new_element) {
        /// inserts an element at the start of the list
            this->insert(new_element, 0);
        }
        void push_back(T new_element) {
        /// inserts an element at the end of the list
            this->insert(new_element, _size);
        }
        void erase(unsigned long index) {
        /// erases an element from the given index of the list
            if (index < 0 || index >= _size) {
                std::ostringstream error_msg;
                error_msg << "called insert(" << index << ") on a list of size " << _size;
                throw std::out_of_range(error_msg.str());
            }
            Node* elem = this->_head;
            for (unsigned long i = 0; i < index; ++i) {
                elem = elem->next;
            }
            if (index != 0)
                elem->prev->next = elem->next;
            else
                this->_head = elem->next;
            if (index != _size - 1)
                elem->next->prev = elem->prev;
            else
                this->_tail = elem->prev;
            delete elem;
            _size--;
        }
        void pop_front() {
        /// erases an element from the start of the list
            this->erase(0);
        }
        void pop_back() {
        /// erases an element from the end of the list
            this->insert(_size - 1);
        }
        void clear() {
        /// erases all elements from the list
            for (unsigned long i = _size - 1; i > 0; --i)
                this->erase(i);
            this->erase(0);
        }
        void assign(T carray[], unsigned long carray_size, unsigned long index=0) {
        /// assign content of an C array to this list
            for (unsigned long i = 0; i < carray_size; ++i) {
                this->insert(carray[i], index+i);
            }
        }
        void assign(T value, unsigned long amount, unsigned long index=0) {
        /// assign *amount* of *value* to this list
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
        bool operator== (const List<T>& myList) const {
            return this->compare(myList);
        }
        bool operator!= (const List<T>& myList) const {
            return !this->compare(myList);
        }
        friend std::ostream& operator<< (std::ostream& myStream, const List<T>& myList) {
            Node* node = myList._head;
            while (node->next) {
                myStream << node->data << ", ";
                node = node->next;
            }
            myStream << node->data << std::endl;
            return myStream;
        }
    };
};

#endif /* ads_list_hpp */
