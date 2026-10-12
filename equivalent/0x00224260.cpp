// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 42/42)
// FUN_00224260 @ 0x00224260
struct Sink;
struct Target {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual bool v11(int a, int b, Sink *c, float amount);
};

struct Sink {
    void FUN_00221ee0();
};

struct Entry {
    Target *target;         // 0x00
    char pad04[0x14 - 0x4];
    int key;                // 0x14
    float f18;              // 0x18
    char pad1c[0x24 - 0x1c];
    float w;                // 0x24
};

extern void __cdecl FUN_00223dc0(Entry *first, Entry *last, int count);

struct Mixer {
    char pad0[0x68];
    unsigned count;                         // 0x68
    Entry e[16];                            // 0x6c
    char dirty;                             // 0x2ec
    bool FUN_00224260(int a, int b, Sink *sink);
};

bool Mixer::FUN_00224260(int a, int b, Sink *sink)
{
    if (!(count > 0))
        return false;
    bool any = false;
    if (dirty != 0) {
        Entry *begin = &e[0];
        Entry *end = begin + count;
        dirty = 0;
        FUN_00223dc0(begin, end, end - begin);
    }
    int k0 = e[0].key;
    double S = e[0].w;
    int cur = k0;
    unsigned j = 0;
    float s;
    float P = 0.0f;
    unsigned n = count;
    if (n > 1) {
        unsigned i = 1;
        do {
            int ki = e[i].key;
            if (ki != cur) {
                if (cur == k0)
                    s = 1.0f;
                else if (!(S > 0.0))
                    s = 0.0f;
                else if (!(S > 1.0))
                    s = (float)S;
                else
                    s = 1.0f;
                double v = e[i].f18 * e[i].w;
                Target *t0 = e[j].target;
                P = (float)v;
                if (t0->v11(a, b, sink, s))
                    any = true;
                for (unsigned k = j + 1; k < i; k++) {
                    double c = e[k].w * e[k].f18;
                    Target *tk = e[k].target;
                    double Q = P + c;
                    P = (float)Q;
                    float amt;
                    if (Q > 0.0)
                        amt = (float)(c / P * s);
                    else
                        amt = 0.0f;
                    if (tk->v11(a, b, sink, amt))
                        any = true;
                }
                S = 0.0;
                cur = ki;
                j = i;
            }
            S = S + e[i].w;
            n = count;
            i++;
        } while (i < n);
    }
    if (cur == k0)
        s = 1.0f;
    else if (!(S > 0.0))
        s = 0.0f;
    else if (!(S > 1.0))
        s = (float)S;
    else
        s = 1.0f;
    {
        double v = e[j].w * e[j].f18;
        Target *tj = e[j].target;
        P = (float)v;
        if (tj->v11(a, b, sink, s))
            any = true;
    }
    for (unsigned k = j + 1; k < count; k++) {
        double c = e[k].w * e[k].f18;
        Target *tk = e[k].target;
        double Q = P + c;
        P = (float)Q;
        float amt;
        if (Q > 0.0)
            amt = (float)(c / P * s);
        else
            amt = 0.0f;
        if (tk->v11(a, b, sink, amt))
            any = true;
    }
    sink->FUN_00221ee0();
    return any;
}
