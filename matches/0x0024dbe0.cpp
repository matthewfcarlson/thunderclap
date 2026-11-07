#include "decls/address.h"
struct Id_24dbe0 {
    __int64 value;
    Id_24dbe0(const char* s) : value(FUN_002672f0(s, 0, 0)) {}
};
class FUN_0025e6c0 {
  public:
    virtual void f();
    FUN_0025e6c0(const Id_24dbe0&, const Id_24dbe0&, int, int, int);
};
class ListenerEffectPspType : public FUN_0025e6c0 {
  public:
    virtual void f();
    ListenerEffectPspType();
};
ListenerEffectPspType::ListenerEffectPspType()
    : FUN_0025e6c0(Id_24dbe0("Data_Effect"), Id_24dbe0("ListenerEffectPsp"), 0x1000104, 0x38, 8) {}
