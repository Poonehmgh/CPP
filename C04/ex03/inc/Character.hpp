#ifndef CHARACTER_H
# define CHARACTER_H

#include "aMateria.hpp"

class Character : public iCharacter
{
    public:
        Character();
        Character(std::string name);
        Character(Character &src);
        virtual ~Character();
        Character   &operator=(Character &src);
        std::string const &getName() const;
        void equip(aMateria* m);
        void unequip(int idx);
        void use(int idx, iCharacter &target);
        aMateria    *getInventory(int index);
        void        setInventoryAll(aMateria *m);
    private:
        aMateria    *_inventory_[4];
        std::string _name_;
};
#endif