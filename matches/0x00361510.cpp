#include "decls/data/engine/audio.h"
// data: BeatSet = DAT_0042ab2c, Data_Sequence = DAT_0042a620, gManager = DAT_004e7a78

struct Pair {
    int a, b;
};
extern "C" Pair __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364710();
class Manager {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
void __cdecl Target() {
    HULK_SIZE32(AudioBeatSet, 0x8);
    Pair a = FUN_002672f0(((char*)&DAT_0042ab2c), 0, 0);
    Pair b = FUN_002672f0(((char*)&DAT_0042a620), 0, 0);
    (*(Manager*)&DAT_004e7a78).FUN_002584d0(&b, &a, (int)sizeof(AudioBeatSet), (int)__alignof(AudioBeatSet));
    atexit(FUN_00364710);
}
