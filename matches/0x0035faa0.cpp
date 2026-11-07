#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
// data: globalObj = DAT_004e6430, name = DAT_004295d0

extern "C" int __cdecl atexit(void(__cdecl*)());
class MetaType_35faa0 {
  public:
    void FUN_0025fa00(const char*, int);
};
extern "C" void __cdecl FUN_003642f0();
void __cdecl FUN_0035faa0() {
    (*(MetaType_35faa0*)&DAT_004e6430).FUN_0025fa00(DAT_004295d0, 0);
    atexit(FUN_003642f0);
}