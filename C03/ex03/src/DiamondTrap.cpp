# include"../inc/DiamondTrap.hpp"

/***************************CANONICAL FORM************************/

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called.\n";
    // setName("Nameless");
    this->FragTrap::setHitPoints(FragTrap::getHitPoints());
    this->ScavTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string name)
{
    setName(name);
    this->FragTrap::setName(name + "_clap_trap"); //???
    this->FragTrap::setHitPoints(FragTrap::getHitPoints());
    this->ScavTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap \033[0;33m" << name << "\033[0m constructor is called.\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &src): ScavTrap(src), FragTrap(src)
{
    *this = src;
    std::cout << "DiamondTrap " << _name_ << " \033[0m copy constructor is called.\n";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &src)
{
    src.setName(src.getName());
    this->FragTrap::setHitPoints(src.FragTrap::getHitPoints());
    this->ScavTrap::setEnergyPoints(src.ScavTrap::getEnergyPoints());
    this->FragTrap::setAttackDamage(src.FragTrap::getAttackDamage());
    this->FragTrap::setName(src.getName() + "_clap_trap"); //what abt functions?
    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap \033[0;33m" << _name_ << "\033[0m destructor is called.\n";
}

void    DiamondTrap::setName(std::string name)
{
    _name_ = name;
}

std::string DiamondTrap::getName(void) const
{
    return (_name_);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << " Hi! I'm \033[0;33m" << getName() << "\033[0m and my ancesterial name is \033[0;33m" << FragTrap::getName() <<"\033[0m\n";
}