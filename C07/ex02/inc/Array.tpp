
// # include "Array.hpp"

template<typename T>
class Array
{
    public:
        Array()
        {
            _element_ = new(T);
        }
        Array(unsigned int l)
        {
            _l_ = l;
            _element_ = new (T * l);
        }
        Array(Array const &src)
        {
            if (this = &src)
                return (src);
            for (int i = 0; i < _l_ ; i++)
            {
                this->_element_[i] = new(T);
                this->_element_[i] = src._element[i];
            }
        }
        Array   &operator=(Array    const &src)
        {
            
        }


    private:
        T               *_element_;
        unsigned int    _l_;


};