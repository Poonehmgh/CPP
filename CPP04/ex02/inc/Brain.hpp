# ifndef brain_H
# define brain_H

#include "../inc/aAnimal.hpp"

class Brain
{
    public:
    Brain();
    ~Brain();
    Brain(Brain const &src);
    Brain &operator=(Brain const &src);
    void    setIdea(std::string idea);
    std::string getIdea(int i) const;
    int         getIndex() const;
    private:
    std::string _ideas_[100];
    int         _index_;
};

#endif