#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"
// data: gEffect = DAT_004e6360 (records.h), gName = DAT_00429490

class MetaType_35fa20 {
  public:
    void FUN_0025fa00(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003642b0();
void __cdecl initEffect() {
    (*(MetaType_35fa20*)&DAT_004e6360).FUN_0025fa00(DAT_00429490, 0);
    atexit(FUN_003642b0);
}
