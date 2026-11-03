// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c5c40 @ 0x000c5c40
#include "gen/owners.h"
struct Triple_c5c40 { unsigned int x,y,z; };
struct Object {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void setPair(unsigned int a,unsigned int b);
 virtual void getPair(unsigned int* a,unsigned int* b);
 virtual void setFirst(float value);
 virtual float getFirst();
 virtual void setSecond(float value);
 virtual float getSecond();
 char padding[0xcc];
 Triple_c5c40 position;
 Triple_c5c40 first;
 Triple_c5c40 second;
 void FUN_00293ac0(Triple_c5c40* value);
};
void __cdecl FUN_000c5c40(Object* source,Object* destination) {
 destination->setFirst(source->getFirst());
 destination->setSecond(source->getSecond());
 unsigned int a,b;
 source->getPair(&a,&b);
 destination->setPair(a,b);
 Triple_c5c40 value = source->first;
 ((owners::C_293a90 *)destination)->FUN_00293a90((int *)(Triple_c5c40 *)(&value));
 value = source->second;
 destination->FUN_00293ac0(&value);
 value = source->position;
 ((owners::C_293af0 *)destination)->FUN_00293af0((int *)(Triple_c5c40 *)(&value));
}