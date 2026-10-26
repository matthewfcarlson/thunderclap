#include "decls/data/engine/audio.h"
// data: reg = DAT_004e60c8

typedef unsigned __int64 U64;
extern U64 __cdecl getName(const char*, int, int);
extern int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
class Registry {
  public:
    void add(const U64*, const U64*, int, int);
};
void init() {
    U64 a = getName("SeqPlayerLayer", 0, 0);
    U64 b = getName("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e60c8).add(&b, &a, 0x78, 4);
    atexit(cleanup);
}
