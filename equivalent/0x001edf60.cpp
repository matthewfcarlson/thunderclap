// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_001edf60 @ 0x001edf60
class Volume_1edf60 {
  public:
    void FUN_001f3950(float v);
};
class Loader_1edf60 {
  public:
    void FUN_001eb060(int a, int b);
};
class Engine_1edf60 {
  public:
    Volume_1edf60* volume;
    Loader_1edf60* loader;
    void FUN_001efa40(int a, const char* name, int b);
    void FUN_001f22f0(float dt, int flag);
};
extern unsigned char DAT_004e36e0;

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
    if (DAT_004e36e0)
        return;
    engine->loader->FUN_001eb060(0, 0);
    engine->FUN_001efa40(1, "frontend", 0);
    float v = level;
    if (!(v < 0.0f) && !(v > 100.0f))
        engine->volume->FUN_001f3950(v);
    FUN_001ec480("", "Enter");
    FUN_001ec480("", "Boot");
    for (int i = 0; i < 10; i++) {
        if (active)
            engine->FUN_001f22f0(0.001f, 0);
    }
    DAT_004e36e0 = 1;
}
