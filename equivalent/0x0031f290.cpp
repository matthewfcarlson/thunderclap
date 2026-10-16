// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::pddiBaseContext::vfunc_87 @ 0x0031f290
#include "gen/pure3d.h"

namespace pure3d {
struct StateA_31f290 {
    int a0;
    int a4;
    char c8;
    int ac;
    char c10;
    int d14;
    char c18;
    char c19;
    char c1a;
    char c1b;
};
struct StateB_31f290 {
    char data[0x34];
    void FUN_0031eab0(const StateB_31f290* prev);
};
struct StateC {
    char data[0x3ec];
    void FUN_0031eb70(const StateC* prev);
};
struct StateD {
    int a0;
    char c4;
    int a8;
    int ac;
    int a10;
};
struct StateE {
    int a0;
    char c4;
    int a8;
    int ac;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
};
template <class T>
struct StateStack_31f290 {
    int field_00;
    int field_04;
    int top;
    T* items;
};
}
void pure3d::pddiBaseContext::vfunc_87(int __p0) { unsigned char flags = (unsigned char)__p0;

    if (flags & 1) {
        (*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->top++;
        StateA_31f290* cur = &(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->items[(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->top];
        const StateA_31f290* prev = cur - 1;
        cur->a4 = prev->a4;
        cur->c8 = prev->c8;
        cur->ac = prev->ac;
        cur->c10 = prev->c10;
        cur->d14 = prev->d14;
        cur->c18 = prev->c18;
        cur->c19 = prev->c19;
        cur->c1a = prev->c1a;
        cur->c1b = prev->c1b;
        (*(StateA_31f290 * *)&this->f_4c) = &(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->items[(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->top];
    }
    if (flags & 2) {
        (*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->top++;
        StateB_31f290* cur = &(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->items[(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->top];
        cur->FUN_0031eab0(cur - 1);
        (*(StateB_31f290 * *)&this->f_48) = &(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->items[(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->top];
    }
    if (flags & 4) {
        (*(StateStack_31f290<StateC> * *)&this->f_3c)->top++;
        StateC* cur = &(*(StateStack_31f290<StateC> * *)&this->f_3c)->items[(*(StateStack_31f290<StateC> * *)&this->f_3c)->top];
        cur->FUN_0031eb70(cur - 1);
        (*(StateC * *)&this->f_50) = &(*(StateStack_31f290<StateC> * *)&this->f_3c)->items[(*(StateStack_31f290<StateC> * *)&this->f_3c)->top];
    }
    if (flags & 8) {
        (*(StateStack_31f290<StateD> * *)&this->f_40)->top++;
        StateD* cur = &(*(StateStack_31f290<StateD> * *)&this->f_40)->items[(*(StateStack_31f290<StateD> * *)&this->f_40)->top];
        const StateD* prev = cur - 1;
        cur->c4 = prev->c4;
        cur->a8 = prev->a8;
        cur->ac = prev->ac;
        cur->a10 = prev->a10;
        (*(StateD * *)&this->f_54) = &(*(StateStack_31f290<StateD> * *)&this->f_40)->items[(*(StateStack_31f290<StateD> * *)&this->f_40)->top];
    }
    if (flags & 0x10) {
        (*(StateStack_31f290<StateE> * *)&this->f_44)->top++;
        StateE* cur = &(*(StateStack_31f290<StateE> * *)&this->f_44)->items[(*(StateStack_31f290<StateE> * *)&this->f_44)->top];
        const StateE* prev = cur - 1;
        cur->c4 = prev->c4;
        cur->a8 = prev->a8;
        cur->ac = prev->ac;
        cur->a10 = prev->a10;
        cur->a14 = prev->a14;
        cur->a18 = prev->a18;
        cur->a1c = prev->a1c;
        cur->a20 = prev->a20;
        (*(StateE * *)&this->f_58) = &(*(StateStack_31f290<StateE> * *)&this->f_44)->items[(*(StateStack_31f290<StateE> * *)&this->f_44)->top];
    }
}
