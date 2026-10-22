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
class SeqEventType_250f60 {
  public:
    SeqEventType_250f60(Name*, const Arg&, int, int) throw();
    virtual void f();
};
class SeqEventStopTrackType_250f60 : public SeqEventType_250f60 {
  public:
    SeqEventStopTrackType_250f60();
    virtual void f();
};
SeqEventStopTrackType_250f60::SeqEventStopTrackType_250f60() : SeqEventType_250f60(Name().Init("Stop", 0), Arg(), 32, 4) {}