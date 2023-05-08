#ifndef Array_h
# define Array_h
# include<iostream>
# include <exception>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

template<typename T>
class Array
{
    public:
        Array() 
        {
            _element_ = new T;
            _l_ = 1;
            std::cout << "default constructor is called.\n";
        };
        Array(unsigned int l) : _l_(l)
        {
            // if (_element_)
            // {
            //     delete _element_;
            //     _element_ = NULL;
            // }
            _element_ = new T[_l_]; 
            std::cout << "constructor is called.\n";
        };
        Array(Array const &src)
        {
            _l_ = src.size();
            for (unsigned int i = 0; i < _l_ ; i++)
            {
                this->_element_[i] = *new T;
                this->_element_[i] = src._element[i];
            }
        }
        Array   &operator=(Array    const &src)
        {
            if (this == &src)
                return (*this);

            try {
                if (_l_ == 0)
                    throw(IndexInvalid());
                delete _element_;
                _l_ = src.size();
                _element_ = new T[_l_];
                for (unsigned int i = 0; i < _l_; i++)
                    _element_[i] = src._element_[i];
            }
            catch(std::exception &e)
            {
                std::cout << RED << e.what() << RESET;
            }
            return (*this);
        }
        ~Array()
        {
            delete[] _element_;
            std::cout << "destructor is called.\n";
        }
        class IndexInvalid: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Invalid index.\n");
            }
        };
        T   operator[](unsigned int i) const
        {
            try
            {
                if (i > _l_ - 1 || _l_ == 0)
                    throw(IndexInvalid());
                return (_element_[i]);
            }
            catch(std::exception &e)
            {
                std::cout << RED << e.what() << RESET;
                return (0);
            }
        }

        void    setElement(T    element, unsigned int i)
        {
            try
            {
                if (i >= _l_)
                    throw(IndexInvalid());
                this->_element_[i] = element;
            }
            catch(const std::exception& e)
            {
                std::cerr << RED << e.what() << RESET;
            }
            
        }
        int    size() const
        {
            return (_l_);
        }
        T getElement(unsigned int i)
        {
            try {
                if (i > _l_)
                    throw (IndexInvalid());
                return(_element_[i]);
            } catch (std::exception &e)
            {
                std::cout  << RED << e.what() << RESET;
                return (0);
            }
        }
    private:
        T               *_element_;
        unsigned int    _l_;
};

#endif
