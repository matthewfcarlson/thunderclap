#include "decls/data/records.h"
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    virtual void f();
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
};
class SeqEventVarTempoType_252d00 : public FUN_002605e0 {
  public:
    virtual void f();
    SeqEventVarTempoType_252d00();
};
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
SeqEventVarTempoType_252d00::SeqEventVarTempoType_252d00()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("4/4", 0), FUN_002672f0("SeqEventVarTempo", 0, 0), (int)sizeof(AudioSeqEventVarTempo), (int)__alignof(AudioSeqEventVarTempo)) { HULK_SIZE32(AudioSeqEventVarTempo, 0x14); }