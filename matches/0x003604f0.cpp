#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e6d98

typedef unsigned __int64 U64;
extern U64 __cdecl Hash(const char*, int, int);
class Registry {
  public:
    void Init(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl target() {
    U64 a = Hash("ChannelVolumeFadeBehaviour", 0, 0);
    U64 b = Hash("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6d98).Init(&b, &a, 0x24, 4);
    atexit(cleanup);
}