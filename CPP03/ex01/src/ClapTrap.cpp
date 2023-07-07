#include"../inc/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor is called.\n";
    _hitPoints_ = 10;
    _energyPoints_ = 10;
    _attackDamage_ = 0 ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Desctructor called.\n";
}

ClapTrap::ClapTrap(std::string name) : _name_(name)
{
    std::cout << "ClapTrap Constructor called.\n";
    _hitPoints_ = 10;
    _energyPoints_ = 10;
    _attackDamage_ = 0 ;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &src)
{
    _name_ = src.getName();
    _energyPoints_ = src.getEnergyPoints();
    _hitPoints_ = src.getHitPoints();
    _attackDamage_ = src.getAttackDamage();
    return (*this);
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints_ && _hitPoints_)
    {
        std::cout << "ClapTrap \033[32m" << _name_ << "\033[0m attacks " << target << " , causing " << _attackDamage_ <<" points of damage!\n";
        _energyPoints_ -= 1;
        return ;
    }
    std::cout << "No energyPoint and/or hitPoints left for ClapTrap \033[32m" << _name_ << "\033[0m. She cannot attack.\n";
    return ;   
}

void ClapTrap::takeDamage(unsigned int amount)
{

    _hitPoints_ -= amount;
    if ( _hitPoints_ <= 0 )
        std::cout <<  "ClapTrap \033[36m" << _name_ << "\033[0m has no points left. She needs to be repaired. hitpoints: " <<_hitPoints_ << "\n";
    else
        std::cout << "ClapTrap \033[36m" << _name_ << "\033[0m has been attacked and got " << amount << " damage. hit points: " << _hitPoints_ << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{    
    if (!_energyPoints_)
    {
            std::cout << "ClapTrap \033[36m " << "\033[0mhas no energy points to repair herself! hitpoints: " << _hitPoints_ <<"\n";
            return ;
    }
    _hitPoints_ += amount;
    _energyPoints_ -= 1;
    std::cout << "ClapTrap \033[36m" << _name_ << "\033[0m has repaired  herself and got " << amount << " hit points. hitpoits: " << _hitPoints_ << "\n";
}

void    ClapTrap::setAttackDamage(int damage)
{
    _attackDamage_ = damage;
}

std::string ClapTrap::getName() const
{
    return(_name_);
}

int     ClapTrap::getAttackDamage() const
{
    return(_attackDamage_);
}

int ClapTrap::getEnergyPoints() const
{
    return(_energyPoints_);
}

int ClapTrap::getHitPoints() const
{
    return (_hitPoints_);
}