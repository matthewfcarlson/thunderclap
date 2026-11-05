#include "decls/data/engine/om.h"

class Obj {
  public:
    void FUN_002455e0();
    Obj();
    ~Obj();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_003641b0() {
    (*(Obj*)&DAT_004e5f18).~Obj();
}
void FUN_0035f500() {
    ((Obj*)&DAT_004e5f18)->FUN_002455e0();
    atexit(FUN_003641b0);
}