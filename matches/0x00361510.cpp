#include "decls/data/engine/audio.h"
// data: BeatSet = DAT_0042ab2c, Data_Sequence = DAT_0042a620, gManager = DAT_004e7a78

struct Pair {
    int a, b;
};
extern "C" Pair __cdecl Find(const char*, int, int);
extern "C" void __cdecl AtExit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
class Manager {
  public:
    void Init(Pair*, Pair*, int, int);
};
void __cdecl Target() {
    Pair a = Find(((char*)&DAT_0042ab2c), 0, 0);
    Pair b = Find(((char*)&DAT_0042a620), 0, 0);
    (*(Manager*)((char*)&DAT_004e7a2c + 76)).Init(&b, &a, 8, 4);
    AtExit(Cleanup);
}
