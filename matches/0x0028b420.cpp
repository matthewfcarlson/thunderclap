#include "gen/owners.h"
extern "C" void* __cdecl AllocA(unsigned int) throw();
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();
class Owner_28b420 {
  public:
    virtual void V() throw();
};
class Channel {
  public:
    virtual ~Channel() throw();
    int a, b;
    Channel() throw() : a(-1), b(0) {}
};
class SimpleChannel : public Channel {
  public:
    virtual ~SimpleChannel() throw();
    Owner_28b420* c;
    int d;
    char* e;
    SimpleChannel(int size, Owner_28b420* owner) throw();
};
SimpleChannel::SimpleChannel(int size, Owner_28b420* owner) throw() : c(owner), d(size), e(0) {
    if (owner == 0)
        e = (char*)AllocA(size * 2);
    else {
        e = (char*)((void *)((owners::C_2888c0 *)owner)->FUN_002888c0((unsigned)(size * 2), 3));
        Owner_28b420* o = c;
        o->V();
    }
    memset(e, 0, d * 2);
}
