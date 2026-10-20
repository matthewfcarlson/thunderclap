#include "compat/ptr.h"
extern "C" __int64 __cdecl make(const char*, int, hulk_intptr);
struct Arg {
    __int64 val;
    Arg() throw() : val(make("SeqEventStopTrack", 0, 0)) {}
};
class Name {
  public:
    char pad[12];
    Name* Init(const char*, int) throw();
    ~Name() throw();
};
class Base {
  public:
    Base(Name*, const Arg&, int, int) throw();
    virtual void f();
};
class audioSeq : public Base {
  public:
    audioSeq();
    virtual void f();
};
audioSeq::audioSeq() : Base(Name().Init("Stop", 0), Arg(), 32, 4) {}