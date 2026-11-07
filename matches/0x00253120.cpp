#include "gen/owners.h"
#include "decls/data/records.h"
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
  public:
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void a();
};
class SeqEventVarPosDistType_253120 : public FUN_002605e0 {
  public:
    SeqEventVarPosDistType_253120() throw();
    virtual void a();
};
SeqEventVarPosDistType_253120::SeqEventVarPosDistType_253120() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("3d", (hulk_intptr)0)), FUN_002672f0("SeqEventVarPosDist", 0, 0), (int)sizeof(AudioSeqEventVarPosDist), (int)__alignof(AudioSeqEventVarPosDist)) { HULK_SIZE32(AudioSeqEventVarPosDist, 0x10); }
