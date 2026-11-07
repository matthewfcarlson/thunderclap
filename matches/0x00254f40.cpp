#include "decls/data/engine/unknown.h"
#include "gen/owners.h"

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
    char pad[12];

  public:
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void f();
};
class SeqEventLogicOrType_254f40 : public FUN_002605e0 {
  public:
    SeqEventLogicOrType_254f40() throw();
    virtual void g();
};
SeqEventLogicOrType_254f40::SeqEventLogicOrType_254f40() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40(((char*)&DAT_00426608), (hulk_intptr)0)), FUN_002672f0("SeqEventLogicOr", 0, 0), (int)sizeof(AudioSeqEventLogicOr), (int)__alignof(AudioSeqEventLogicOr)) { HULK_SIZE32(AudioSeqEventLogicOr, 0x18); }