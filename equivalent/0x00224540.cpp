// STATUS: equivalent (tools/equiv.py level 3: 2647 inputs, branch coverage 42/42)
// FUN_00224540 @ 0x00224540
// FUN_00224540 @ 0x00224540
// Weighted blend of a run of layers. Consecutive entries with the same key form a group; the first layer of
// each finished group is sampled with the weight accumulated so far (clamped to 0..1), the rest of the group
// share the remaining weight in proportion to their a*b contribution. Returns true if any layer produced a
// value; *out is blended towards each layer's value.
struct Layer_224540 {
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
    virtual bool v12(unsigned ctx, float *out);
};

struct Entry_224540 {
    Layer_224540 *layer;
    char pad0[0x10];
    unsigned key;
    float a;
    char pad1[8];
    float b;
};

// The original keeps all its locals in one 0x28-byte frame in this order; layer callbacks write through
// &out, so the neighbouring words matter.
struct Frame_224540 {
    char pad[3];
    bool changed;       // 0x13
    float f14;          // weight of the finished group / out value of the final layer
    float f18;          // out value / final weight
    float sum;          // 0x1c
    unsigned start;     // 0x20
    float w2;           // 0x24
    unsigned i;         // 0x28
    unsigned t2c;
    unsigned k;         // 0x30
    unsigned key0;      // 0x34
};

class Blend_224540 {
public:
    char pad[0x68];
    unsigned count;
    Entry_224540 e[1];

    void FUN_00223f50();
    bool FUN_00224540(unsigned ctx, float *out);
};

bool Blend_224540::FUN_00224540(unsigned ctx, float *result)
{
    if (ctx == 0 || count == 0)
        return false;

    Frame_224540 fr;
    fr.changed = false;
    FUN_00223f50();

    float acc = e[0].b;
    fr.key0 = e[0].key;
    unsigned cur = fr.key0;
    fr.start = 0;
    fr.i = 1;

    if (count > 1) {
        do {
            fr.k = e[fr.i].key;
            if (fr.k != cur) {
                if (cur == fr.key0) {
                    fr.f14 = 1.0f;
                } else if (acc > 0.0f) {
                    if (acc > 1.0f)
                        fr.f14 = 1.0f;
                    else
                        fr.f14 = acc;
                } else {
                    fr.f14 = 0.0f;
                }
                fr.sum = e[fr.i].a * e[fr.i].b;
                fr.f18 = 0.0f;
                if (e[fr.start].layer->v12(ctx, &fr.f18)) {
                    fr.changed = true;
                    *result = (fr.f18 - *result) * fr.f14 + *result;
                }
                for (unsigned j = fr.start + 1; j < fr.i; ++j) {
                    fr.sum = fr.sum + e[j].b * e[j].a;
                    if (fr.sum > 0.0f)
                        fr.w2 = ((e[j].b * e[j].a) / fr.sum) * fr.f14;
                    else
                        fr.w2 = 0.0f;
                    fr.f18 = 0.0f;
                    if (e[j].layer->v12(ctx, &fr.f18)) {
                        fr.changed = true;
                        *result = (fr.f18 - *result) * fr.w2 + *result;
                    }
                }
                acc = 0.0f;
                cur = fr.k;
                fr.start = fr.i;
            }
            acc = acc + e[fr.i].b;
            ++fr.i;
        } while (fr.i < count);
    }

    if (cur == fr.key0) {
        fr.f18 = 1.0f;
    } else if (acc > 0.0f) {
        if (acc > 1.0f)
            fr.f18 = 1.0f;
        else
            fr.f18 = acc;
    } else {
        fr.f18 = 0.0f;
    }

    fr.sum = e[fr.start].b * e[fr.start].a;
    fr.f14 = 0.0f;
    if (e[fr.start].layer->v12(ctx, &fr.f14)) {
        fr.changed = true;
        *result = (fr.f14 - *result) * fr.f18 + *result;
    }
    for (unsigned j = fr.start + 1; j < count; ++j) {
        fr.sum = fr.sum + e[j].b * e[j].a;
        if (fr.sum > 0.0f)
            fr.w2 = ((e[j].b * e[j].a) / fr.sum) * fr.f18;
        else
            fr.w2 = 0.0f;
        fr.f14 = 0.0f;
        if (e[j].layer->v12(ctx, &fr.f14)) {
            fr.changed = true;
            *result = (fr.f14 - *result) * fr.w2 + *result;
        }
    }
    return fr.changed;
}
