#include "../inc/MatriaSource.hpp"

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if (_source_[i])
        {
            delete _source_[i];
            _source_[i] = NULL;
        }
    }
}

MateriaSource::MateriaSource()
{
    _index_ = 0; 
    for (int i = 0; i < 4; i++) //check
        _source_[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    _index_ = src._index_;
    for (int i = 0; i < 4; i++)
    {
        if (src._source_[i])
            _source_[i] = src._source_[i]->clone();
        else
            _source_[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource &src)
{
    _index_ = src._index_;
    for (int i = 0; i < 4; i++)
    {
        if (src._source_[i])
            _source_[i] = src._source_[i]->clone();
        else
            _source_[i] = NULL;
    }
    return (*this);
}

void    MateriaSource::learnMateria(aMateria *m)
{
    if (_index_ >= 4)
        std::cout << "Source is full!\n";
    if (_index_ < 4)
    {
        _source_[_index_] = m;
        _index_++;
    }
    
}

aMateria    *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_source_[i] && _source_[i]->getType() == type)
            return (_source_[i]->clone());
    }
    return (0);
}