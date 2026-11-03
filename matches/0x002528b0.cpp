#include "gen/owners.h"
typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
class Temp {
    char data[12];

  public:
    ~Temp() throw();
};
class SeqEventType_2528b0 {
  public:
    SeqEventType_2528b0(Temp*, const U64&, int, int) throw();
    virtual void v();
};
class SeqEventVarVolumeType_2528b0 : public SeqEventType_2528b0 {
  public:
    SeqEventVarVolumeType_2528b0() throw();
    virtual void v();
};
SeqEventVarVolumeType_2528b0::SeqEventVarVolumeType_2528b0() throw()
    : SeqEventType_2528b0(((Temp *)((owners::String_23fc40 *)&(Temp()))->FUN_0023fc40("Vol", (hulk_intptr)0)), FUN_002672f0("SeqEventVarVolume", 0, 0), 12, 4) {}