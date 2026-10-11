// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 18/18)
// FUN_001c0360 @ 0x001c0360
struct Vec3 { float x, y, z; };

extern float DAT_004de600;
extern float DAT_004de604;
extern float DAT_004e2308;
extern float DAT_004e230c;
extern float DAT_004e2310;
extern float DAT_004c4c40;

struct Entry {
    float a;
    float b;
    int c;
    int d;
};

struct Child {
    char pad0[8];
    int field08;
    char flag0c;
    char pad0d[3];
    int field10;
    int field14;
    char pad18[4];
    short word1c;
};

struct Source {
    char pad0[0x2c];
    int field2c;
};

struct Holder {
    Source *FUN_000862b0();
};

float __cdecl FUN_000f6a70(int a, Vec3 *v, int target);

class Shake {
public:
    float value;
    int count;
    Entry *entries;
    char pad0c;
    char flag0d;
    char pad0e[0x12];
    int mode;
    char flag24;
    char pad25[7];
    Child *child;
    char pad30[8];
    int target;
    char pad3c[0x10];
    Holder *holder;
    int field50;
    char pad54;
    char flag55;
    void FUN_001c0360(int newMode, int newCount);
};

void Shake::FUN_001c0360(int newMode, int newCount)
{
    if (entries != 0 || count != 0) {
        count = 0;
        value = -1.0f;
        flag0d = 0;
        flag24 = 0;
        flag55 = 0;
        if (mode == 2)
            child->flag0c = 0;
        Child *c = child;
        field50 = 0;
        c->flag0c = 0;
        c->field10 = 0;
        c->field08 = 0;
        c->field14 = 0;
        c->word1c = 0;
    }
    mode = newMode;
    value = -1.0f;
    if (newCount > 0x46)
        return;
    count = newCount;
    for (int i = 0; i < count; i++) {
        Entry *e = &entries[i];
        e->a = -1.0f;
        e->b = -1.0f;
    }
    switch (mode) {
    case 0:
    case 1:
        DAT_004e2308 = 0.0f;
        DAT_004e230c = 0.0f;
        DAT_004e2310 = 0.0f;
        break;
    case 2: {
        DAT_004e2310 = 0.0f;
        float a = DAT_004de600;
        float b = DAT_004de604;
        float ha = a * -0.5f;
        float hb = b * -0.5f;
        float sa = a * 0.6f;
        DAT_004e2308 = sa + ha;
        DAT_004e230c = b * 0.26f + hb;
        Source *src = holder->FUN_000862b0();
        Vec3 v;
        v.x = DAT_004de600 * -0.5f;
        v.z = 0.0f;
        v.y = DAT_004de604 * 0.5f;
        DAT_004c4c40 = FUN_000f6a70(src->field2c, &v, target);
        break;
    }
    }
}
