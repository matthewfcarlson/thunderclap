// FUN_001edf60 @ 0x001edf60
#include "decls/data/game/global.h"
#include "gen/owners.h"

class Volume_1edf60 {
  public:
};
class Loader_1edf60 {
  public:
};
class Engine_1edf60 {
  public:
    Volume_1edf60* volume;
    Loader_1edf60* loader;
    void FUN_001efa40(int a, const char* name, int b);
    void FUN_001f22f0(float dt, int flag);
};

class Boot {
  public:
    Engine_1edf60* engine;
    char pad0[4];
    char active;
    char pad1[3];
    float level;
    void FUN_001ec480(const char* a, const char* b);
    void FUN_001edf60();
};

void Boot::FUN_001edf60() {
    if ((*(unsigned char*)&DAT_004e36e0))
        return;
    ((owners::Manager_1eb060 *)(engine->loader))->FUN_001eb060((const char *)(hulk_uintptr)(int)0, (const char *)(hulk_uintptr)(int)0);
    engine->FUN_001efa40(1, "frontend", 0);
    float v = level;
    if (!(v < 0.0f) && !(v > 100.0f))
        ((owners::Obj_1f3950 *)(engine->volume))->FUN_001f3950(v);
    FUN_001ec480("", "Enter");
    FUN_001ec480("", "Boot");
    for (int i = 0; i < 10; i++) {
        if (active)
            engine->FUN_001f22f0(0.001f, 0);
    }
    (*(unsigned char*)&DAT_004e36e0) = 1;
}
