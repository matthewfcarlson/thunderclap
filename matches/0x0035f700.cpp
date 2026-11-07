#include "decls/data/engine/audio.h"
// data: reg = DAT_004e60c8

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
extern int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364220();
class Registry {
  public:
    void FUN_002584d0(const U64*, const U64*, int, int);
};
void init() {
    HULK_SIZE32(AudioSeqPlayerLayer, 0x78);
    U64 a = FUN_002672f0("SeqPlayerLayer", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e60c8).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqPlayerLayer), (int)__alignof(AudioSeqPlayerLayer));
    atexit(FUN_00364220);
}
