// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035be88..0x00364840 (kind game-init, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x0035de40 FUN_0035de40 (29 B): matches/0x0035de40.cpp [isolated: no out-of-line definition (target defined in a class body); on include/gen/ and not mergeable]
// sym: _$E1

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

#include "gen/owners.h"
class Sound : public owners::String_23fc40 {
  public:
    Sound(const char* s, int o) { FUN_0023fc40(s, (hulk_intptr)o); }
    ~Sound();
};
Sound sound("sound/rsd", 0);

