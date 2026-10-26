#include "decls/data/engine/om.h"

class Obj {
  public:
    Obj();
    ~Obj();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup() {
    (*(Obj*)&DAT_004e5f18).~Obj();
}
void FUN_0035f500() {
    (*(Obj*)&DAT_004e5f18).Obj::Obj();
    atexit(cleanup);
}