#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
// data: sound = DAT_004e14f8

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363f80();
void init() {
    ((owners::String_23fc40 *)&DAT_004e14f8)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363f80);
}