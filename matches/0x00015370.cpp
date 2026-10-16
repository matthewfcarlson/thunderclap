#include "gen/global.h"

struct R5;
struct R4;
struct R2;
struct R1;
struct M_15370;
struct T2;
struct R3;

struct T2 {
    char pad[0x24];
    int f24;
    char pad2[0x12e0 - 0x28];
    int f12e0;
    int f12e4;
    int f12e8;
};

struct R3 {
    char pad[0x68];
    unsigned int f68;
    void* GetElem(unsigned int i);
};

struct R5 {
    R3* Fn();
};

struct R4 {
    char pad[0x10];
    R5* f10;
};

struct R2 {
    char pad[0x338];
    R4* f338;
};

struct R1 {
    R2* Fn();
};

struct M_15370 {
    R1* Fn();
};

extern char g1_15370[];
extern char g2_15370[];
void* FUN_00344e74(void* e, int a, void* b, void* c, int d);

bool CGrappleLocoStrafe4Action::vfunc_7(int arg) {
    if (!(*(T2 * *)&this->f_24))
        return false;
    R1* r1 = (*(M_15370 * *)&this->f_1c)->Fn();
    R2* r2 = r1->Fn();
    R4* r4 = r2->f338;
    if (!r4)
        return false;
    R3* r3 = r4->f10->Fn();
    if (!r3)
        return false;
    for (unsigned int i = 0; i < r3->f68; i++) {
        void* e = r3->GetElem(i);
        T2* p = (T2*)FUN_00344e74(e, 0, g1_15370, g2_15370, 0);
        if (p) {
            (*(T2 * *)&this->f_24)->f24 = p->f24;
            (*(T2 * *)&this->f_24)->f12e4 = p->f12e4;
            (*(T2 * *)&this->f_24)->f12e0 = p->f12e0;
            (*(T2 * *)&this->f_24)->f12e8 = p->f12e8;
            return true;
        }
    }
    return false;
}
