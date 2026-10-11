extern "C" void* __cdecl AllocA(unsigned int) throw();
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();
class Owner {
  public:
    virtual void V() throw();
    void* AllocB(unsigned int, int) throw();
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
    Owner* c;
    int d;
    char* e;
    SimpleChannel(int size, Owner* owner) throw();
};
SimpleChannel::SimpleChannel(int size, Owner* owner) throw() : c(owner), d(size), e(0) {
    if (owner == 0)
        e = (char*)AllocA(size * 2);
    else {
        e = (char*)owner->AllocB(size * 2, 3);
        Owner* o = c;
        o->V();
    }
    memset(e, 0, d * 2);
}
