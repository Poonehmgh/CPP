#include"../inc/Character.hpp"

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory_[i])
        { 
            delete _inventory_[i];
            _inventory_[i] = NULL;
        }
    }
    //std::cout << "Character destructor called.\n";
}

Character::Character()
{
    //std::cout << "Character def constructor called.\n";
    setInventoryAll(NULL);
}

Character::Character(std::string name) : _name_(name)
{
    //std::cout << "Character constructor called.\n";
    setInventoryAll(NULL);
}

Character::Character(Character &src)
{
    _name_ = src.getName();
    for (int i = 0; i < 4; i++)
        _inventory_[i] = src._inventory_[i]->clone(); 
        //std::cout << "Character copy constructor called.\n";
}

Character &Character::operator=(Character &src)
{
    _name_ = src.getName();
    for (int i = 0; i < 4; i++)
    {
        if (_inventory_[i])
            delete _inventory_[i];
        _inventory_[i] = src._inventory_[i]->clone();
    }
    //std::cout << "Character copy operator called.\n";
    return (*this);
}

aMateria    *Character::getInventory(int index)
{
    return (_inventory_[index]);
}

void    Character::equip(aMateria *m)
{
    if (!m)
    {
        std::cout << "empty Materia. Check MateriaSource.\n";
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory_[i])
        {
            _inventory_[i] = m;
            break;
        }
    }
}

void    Character::setInventoryAll(aMateria *m)
{
    for (int i = 0; i < 4; i++)
        _inventory_[i] = m;
}

void    Character::use(int index, iCharacter &target)
{
    if (index > 4 || index < 0)
    {
        std::cout << "Invalid index in use.\n";
        return ;
    }
    if (_inventory_[index])
        _inventory_[index]->use(target);
    else
        std::cout << "Not valid Materia!\n";
}

void    Character::unequip(int index)
{
    if (index > 4 || index < 0)
        std::cout << "This index in invalid.\n";
    if( !_inventory_[index])
        std::cout << "This index of inventory is already empty.\n";
    else
        _inventory_[index] = NULL;
}

std::string const &Character::getName() const
{
    return(_name_);
}