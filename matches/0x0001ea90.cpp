// Same code shape as 0x0001ecb0 (propagated; names are from that function)
#include "gen/global.h"

extern char vftableD[];
extern char vftableA[];

class RefObj_1ea90 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Tidier {
    void Tidy();
};

void CSmartPropAttachAction::FUN_0001ea90() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_1ea90* b = (*(RefObj_1ea90 *volatile *)&this->f_24);
    if (b) {
        b->Release();
        (*(RefObj_1ea90 *volatile *)&this->f_24) = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1ea90* a = (*(RefObj_1ea90 *volatile *)&this->f_1c);
    if (a) {
        a->Release();
        (*(RefObj_1ea90 *volatile *)&this->f_1c) = 0;
    }
    ((Tidier*)this)->Tidy();
}
