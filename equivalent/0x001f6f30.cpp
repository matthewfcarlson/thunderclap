// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f6f30 @ 0x001f6f30
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Emitter {
    void *FUN_002842e0(Id64 *id, int a, int b, void *c, void *d, float *scale, int e, int f);
};

class Spawner {
public:
    char pad00[0x1c];
    int f1c;
    int f20;
    char f24[0x18];         // 0x24
    char f3c[0xc];          // 0x3c
    int f48;                // 0x48
    char pad4c[0xc];
    float scaleA;           // 0x58
    float scaleB;           // 0x5c
    Emitter *FUN_0027f250();
    void *FUN_001f6f30(const char *name, float scale, int arg);
};

void *Spawner::FUN_001f6f30(const char *name, float scale, int arg)
{
    void *result = 0;
    Emitter *emitter = FUN_0027f250();

    scaleA = scale * scaleA;
    scaleB = scale * scaleB;

    if (emitter != 0) {
        Id64 id;
        id.FUN_0027b0e0(name);
        result = emitter->FUN_002842e0(&id, f1c, f20, f24, f3c, &scaleA, arg, f48);
        id.FUN_0027af50();
    }
    return result;
}
