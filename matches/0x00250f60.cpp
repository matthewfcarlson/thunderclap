#include "compat/ptr.h"
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
struct Arg {
    __int64 val;
    Arg() throw() : val(FUN_002672f0("SeqEventStopTrack", 0, 0)) {}
};
class FUN_00240060 {
  public:
    char pad[12];
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const Arg&, int, int) throw();
    virtual void f();
};
class SeqEventStopTrackType_250f60 : public FUN_002605e0 {
  public:
    SeqEventStopTrackType_250f60();
    virtual void f();
};
SeqEventStopTrackType_250f60::SeqEventStopTrackType_250f60() : FUN_002605e0(FUN_00240060().FUN_0023fc40("Stop", 0), Arg(), 32, 4) {}