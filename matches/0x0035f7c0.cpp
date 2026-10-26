#include "decls/data/engine/audio.h"
// data: manager_35f7c0 = DAT_004e6158

typedef unsigned __int64 U64_35f7c0;
extern "C" U64_35f7c0 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Manager_35f7c0 {
  public:
    void Init(U64_35f7c0*, U64_35f7c0*, int, int);
};
void __cdecl target() {
    U64_35f7c0 a = lookup("ChannelSendVolumeArray", 0, 0);
    U64_35f7c0 b = lookup("Runtime_Sequence", 0, 0);
    (*(Manager_35f7c0*)((char*)&DAT_004e6110 + 72)).Init(&b, &a, 256, 4);
    atexit(cleanup);
}