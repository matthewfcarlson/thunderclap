#include "gen/owners.h"
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class Param {
  public:
    ~Param() throw();
    char pad[12];
};
class SeqEventType_253120 {
  public:
    SeqEventType_253120(Param*, const __int64&, int, int) throw();
    virtual void a();
};
class SeqEventVarPosDistType_253120 : public SeqEventType_253120 {
  public:
    SeqEventVarPosDistType_253120() throw();
    virtual void a();
};
SeqEventVarPosDistType_253120::SeqEventVarPosDistType_253120() throw()
    : SeqEventType_253120(((Param *)((owners::String_23fc40 *)&(Param()))->FUN_0023fc40("3d", (hulk_intptr)0)), FUN_002672f0("SeqEventVarPosDist", 0, 0), 16, 4) {}
