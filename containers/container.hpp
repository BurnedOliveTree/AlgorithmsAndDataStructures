#ifndef ads_container_hpp
#define ads_container_hpp

namespace ads {
    template <class T>
    class Container {
    public:
        virtual unsigned long size() const = 0;
        virtual bool empty() const = 0;
        virtual T& front() const = 0;
        virtual T& back() const = 0;
    };
}

#endif /* ads_container_hpp */
