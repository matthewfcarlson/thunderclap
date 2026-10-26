#include "decls/data/engine/audio.h"
// data: registry = DAT_004e67b8

typedef unsigned __int64 U64;
extern U64 __cdecl hash(const char*, int, int);
class Registry {
  public:
    void setup(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl target() {
    U64 a = hash("ChannelSendVolumeFadeBehaviour", 0, 0);
    U64 b = hash("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e67b8).setup(&b, &a, 0x24, 4);
    atexit(cleanup);
}