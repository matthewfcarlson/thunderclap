#include "decls/data/engine/unknown.h"
#include "gen/owners.h"

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class Arg {
    char pad[12];

  public:
    ~Arg() throw();
};
class SeqEventType_254f40 {
  public:
    SeqEventType_254f40(Arg*, const __int64&, int, int) throw();
    virtual void f();
};
class SeqEventLogicOrType_254f40 : public SeqEventType_254f40 {
  public:
    SeqEventLogicOrType_254f40() throw();
    virtual void g();
};
SeqEventLogicOrType_254f40::SeqEventLogicOrType_254f40() throw()
    : SeqEventType_254f40(((Arg *)((owners::String_23fc40 *)&(Arg()))->FUN_0023fc40(((char*)&DAT_00426608), (hulk_intptr)0)), FUN_002672f0("SeqEventLogicOr", 0, 0), 0x18, 4) {}