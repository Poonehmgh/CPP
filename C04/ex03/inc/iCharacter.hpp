#ifndef ICHARACTER_H
# define ICHARACTER_H

class aMateria;
class iCharacter
{
    public:
    virtual ~iCharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(aMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, iCharacter& target) = 0;
};
#endif