#include "decls/data/engine/audio.h"
// data: playName = DAT_00429df8, trackName = DAT_00429e00

typedef unsigned long long U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const U64&, int, int) throw();
    virtual void v0();
};
class SeqEventPlayTrackType : public FUN_002605e0 {
  public:
    SeqEventPlayTrackType();
    virtual void v0();
};
SeqEventPlayTrackType::SeqEventPlayTrackType() : FUN_002605e0(FUN_00240060().FUN_0023fc40(DAT_00429df8, 0), FUN_002672f0(DAT_00429e00, 0, 0), 32, 4) {}