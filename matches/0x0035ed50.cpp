#include "gen/owners.h"
class Registry {
  public:
};

extern Registry g_registry;
extern void Cleanup();

void Init() {
    ((owners::String_23fc40 *)&g_registry)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(Cleanup);
}
