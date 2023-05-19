#ifndef Array_h
# define Array_h
# include<iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int l);
        Array(Array const &src);
        Array   &operator=(Array    const &src);
        ~Array();
        class IndexInvalid: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Invalid index.\n");
            }
        };
        T   &operator[](unsigned int i) const;
        int    size() const;
    private:
        T               *_element_;
        unsigned int    _l_;
};

template<typename T>
Array<T>::Array(): _element_(NULL), _l_(0)
{
    std::cout << "Default constructor is called. array is empty\n";
}

template<typename T>
Array<T>::Array(unsigned int l) : _element_(NULL), _l_(l)
{
    if (_element_)
        delete _element_;
    _element_ = new T[_l_];
    std::cout << "Constructor is called. Array of size " << _l_ << " is created.\n";
}
template<typename T>
Array<T>::Array(Array const &src): _element_(NULL), _l_(src.size()) //not sure about null initialization 
{
    if (_element_)
    {
        delete[] _element_;
        _element_ = NULL;
    }
    _element_ = new T[_l_];
    for (unsigned int i = 0; i < _l_ ; i++)
        _element_[i] = src._element[i];
}

template<typename T>
Array<T> &Array<T>::operator=(Array    const &src)
{
    if (this == &src)
        return (*this);
    if (_element_)
    {
        delete[] _element_;
        _element_ = NULL;
    }
    _l_ = src.size();
    _element_ = new T[_l_];
    for (unsigned int i = 0; i < _l_; i++)
        _element_[i] = src._element_[i];
    return (*this);
}

template<typename T>
Array<T>::~Array()
{
    std::cout << "Destructor is called.";
    if (_element_)
    {
        delete[] _element_;
        _element_ = NULL;
        std::cout << "Array has been deleted.\n";
    }
}

template<typename T>
T   &Array<T>::operator[](unsigned int i) const // it returns a refrence to an element, so when you assign the element to sth in main for example, the refrence would point to that vlue
{
    if (i >= _l_ || i < 0 || _l_ == 0)
        throw(IndexInvalid());
    return (_element_[i]);
}

template<typename T>
int    Array<T>::size() const
{
    return (_l_);
}

#endif
