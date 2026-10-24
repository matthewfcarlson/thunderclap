// Same code shape as 0x0001ecb0 (propagated; names are from that function)
#include "gen/global.h"

extern char vftableD[];
extern char vftableA[];

class RefObj_21490 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Tidier {
    void Tidy();
};

void CHeliDeathSpiralAction::FUN_00021490() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_21490* b = (*(RefObj_21490 *volatile *)&this->f_24);
    if (b) {
        b->Release();
        (*(RefObj_21490 *volatile *)&this->f_24) = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_21490* a = (*(RefObj_21490 *volatile *)&this->f_1c);
    if (a) {
        a->Release();
        (*(RefObj_21490 *volatile *)&this->f_1c) = 0;
    }
    ((Tidier*)this)->Tidy();
}
