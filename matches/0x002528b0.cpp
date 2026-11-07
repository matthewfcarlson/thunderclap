#include "gen/owners.h"
typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
    char data[12];

  public:
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const U64&, int, int) throw();
    virtual void v();
};
class SeqEventVarVolumeType_2528b0 : public FUN_002605e0 {
  public:
    SeqEventVarVolumeType_2528b0() throw();
    virtual void v();
};
SeqEventVarVolumeType_2528b0::SeqEventVarVolumeType_2528b0() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("Vol", (hulk_intptr)0)), FUN_002672f0("SeqEventVarVolume", 0, 0), 12, 4) {}