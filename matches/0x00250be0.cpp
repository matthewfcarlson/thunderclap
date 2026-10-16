#include "decls/data/engine/audio.h"

class Helper_250be0 {
  public:
    void Fn();
};
class SeqEventExpression {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventExpression* v4(int);
    virtual void v5();
    void Fn();
    char pad[8];
};
extern void __cdecl FUN_00247550(void*, void*);
SeqEventExpression* SeqEventExpression::v4(int x) {
    ((Helper_250be0*)((char*)this + 8))->Fn();
    this->Fn();
    if (x & 1)
        FUN_00247550(((char*)&DAT_004e6b18), this);
    return this;
}