#include "gen/audio.h"

class Entity_257b00 {
  public:
    virtual void a();
    virtual void b();
};
void InitA(void*);
void InitB(void*);

bool audio::Sequence::vfunc_4(int __p0) { unsigned int p = (unsigned int)__p0;

    *(void**)((char*)this + 0x28) = (char*)this + 0x2c;
    InitA((char*)this + 0x3c);
    InitB((char*)this + 0x44);
    return (bool)(vfunc_5(p));
}
