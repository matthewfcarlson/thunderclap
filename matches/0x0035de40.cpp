extern "C" int __cdecl atexit(void(__cdecl*)());
#include "gen/owners.h"
class Sound : public owners::String_23fc40 {
  public:
    Sound(const char* s, int o) { FUN_0023fc40(s, (hulk_intptr)o); }
    ~Sound();
};
Sound sound("sound/rsd", 0);
