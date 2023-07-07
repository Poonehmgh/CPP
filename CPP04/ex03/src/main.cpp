#include"../inc/Character.hpp"
#include"../inc/Cure.hpp"
#include"../inc/Ice.hpp"
#include"../inc/MatriaSource.hpp"

int main()
{
    iMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    iCharacter *me = new Character("me");
    aMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    iCharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    /***test for MateriaSource ****/
    {
        iMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Ice());
        src->learnMateria(new Ice());
        iCharacter  *bob = new Character("bob");
        aMateria *tmp = src->createMateria("cure"); //since we have no cube in materiasource, there should be no segfaults. 
        bob->equip(tmp);
    /*** test for capacity of MateriaSource***/
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        tmp = src->createMateria("cure");
        bob->equip(tmp);
        delete src;
        delete bob;
    }
    /*** test when there is no Materia created ***/
    {
        iMateriaSource  *src = new MateriaSource();
        src->createMateria("cure"); 
        delete src;
    }
    /*** test for invalid index / invaluse use/equip input */
    {
        iMateriaSource  *src = new MateriaSource();
        src->learnMateria(new Cure());
        src->createMateria("cure");
        Character *me = new Character("me");
        Character *you = new Character("you");
        me->equip(src->createMateria("cure"));
        aMateria *ptr = me->getInventory(0); //saving the Materia's address before unequiping
        // me->use(2, *you); //invalid index because source is not full at this index
        // me->use(10, *you); //invalid index
        // me->use(0, *me); // can a character .use on themself?
        me->unequip(0);
        // me->use(0, *you); // check after unequiping.
        me->equip(ptr); //reusing the address of dropped Materia;
        me->use(0, *you);
        delete me;
        delete you;
        delete src;
    }
}