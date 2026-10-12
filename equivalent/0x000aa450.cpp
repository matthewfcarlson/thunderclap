// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_000aa450 @ 0x000aa450
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
};

struct Entry {
    V3 pos;
    int rest[9];
};

struct Probe {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void setRange(float range, int flag);   // 0x18
    virtual void v7();
    virtual void v8();
    virtual void reset();                           // 0x24
};

struct Sink {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void commit(int flag);                  // 0x30
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void hit(int target, int a, int b);     // 0x60
};

struct Source {
    bool FUN_00035350(V3 *out);
};

class Tracer {
public:
    char pad0[0x170];
    Source *source;                 // 0x170
    int field174;                   // 0x174
    V3 origin;                      // 0x178
    char pad184[0x190 - 0x184];
    Entry best;                     // 0x190
    int field1c0;                   // 0x1c0
    char pad1c4[0x424 - 0x1c4];
    Sink *sink;                     // 0x424
    char pad428[4];
    float matrix[16];               // 0x42c
    char pad46c[0x478 - 0x46c];
    Probe *probe;                   // 0x478
    unsigned char flag47c;          // 0x47c
    unsigned char flag47d;          // 0x47d

    V3 *FUN_000a92c0(V3 *out, int a, Source *s);
    char FUN_000aa130(int target, float *m, Entry *out);
    char FUN_000aa450(int a1, float *m, int *targets, int count, Source *src, int a6, int a7);
};

char Tracer::FUN_000aa450(int a1, float *m, int *targets, int count, Source *src, int a6, int a7)
{
    struct Frame {
        float bestDist;
        V3 tmp;
        Entry e[4];
    } f;

    source = src;
    if (!src->FUN_00035350(&origin)) {
        V3 *p = FUN_000a92c0(&f.tmp, a1, source);
        origin = *p;
    }

    int idx = -1;
    f.bestDist = 1.0e12f;
    for (int i = 0; i < count; ++i) {
        if (FUN_000aa130(targets[i], m, &f.e[i])) {
            float dx = f.e[i].pos.x - origin.x;
            float dy = f.e[i].pos.y - origin.y;
            float dz = f.e[i].pos.z - origin.z;
            double len = sqrt((double)(dz * dz + dy * dy + dx * dx));
            if (idx < 0 || len < f.bestDist) {
                f.bestDist = (float)len;
                idx = i;
            }
        }
    }

    if (idx < 0)
        return 0;
    if (f.bestDist > 1000.0f)
        return 0;

    best = f.e[idx];
    sink->hit(targets[idx], 0, 0);
    sink->commit(0);
    for (int i = 0; i < 16; ++i)
        matrix[i] = m[i];
    field174 = a6;
    field1c0 = a7;
    if (probe) {
        probe->reset();
        probe->setRange(300.0f, 0);
    }
    flag47c = 0;
    flag47d = 0;
    return 1;
}
