#include "decls/data/engine/audio.h"
// data: globalObj = DAT_004e6430, name = DAT_004295d0

extern "C" int __cdecl atexit(void(__cdecl*)());
class MetaType_35faa0 {
  public:
    void Init(const char*, int);
};
void __cdecl cleanup();
void __cdecl FUN_0035faa0() {
    (*(MetaType_35faa0*)((char*)&DAT_004e63fc + 52)).Init(DAT_004295d0, 0);
    atexit(cleanup);
}