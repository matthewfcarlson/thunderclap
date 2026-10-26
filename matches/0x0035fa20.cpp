#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
// data: gEffect = DAT_004e6360, gName = DAT_00429490

class MetaType_35fa20 {
  public:
    void Init(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl initEffect() {
    (*(MetaType_35fa20*)((char*)&DAT_004e635c + 4)).Init(DAT_00429490, 0);
    atexit(cleanup);
}
