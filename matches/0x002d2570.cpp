#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"

class Chunk {
  public:
    int Find(int a, int b);
};

class NonCopyable_2d2570 {
  public:
    NonCopyable_2d2570() : mA(0) {}
    virtual void f0();
    int mA;
};

class GeneratorBlendState_2d2570 : public NonCopyable_2d2570 {
  public:
    GeneratorBlendState_2d2570(Chunk* c);
    virtual void f0();
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

GeneratorBlendState_2d2570::GeneratorBlendState_2d2570(Chunk* c) {
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    if (c) {
        m8 = c->Find(((hulk_intptr)((char*)0x544457)), 0x31544c46);
        mC = c->Find(((hulk_intptr)((char*)0x544748)), 0x31544c46);
        m10 = c->Find(0x50534f48, 0x31544c46);
        m14 = c->Find(0x50534556, 0x31544c46);
        m18 = c->Find(0x41564452, 0x31544c46);
    }
}
