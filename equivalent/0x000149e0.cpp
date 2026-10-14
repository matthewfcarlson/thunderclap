// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/14, incomplete)
// FUN_000149e0 @ 0x000149e0
struct Table_149e0 {
    float FUN_00069620(int i);
    float FUN_000695e0(int i);
};

struct Info_149e0 {
    char pad0[0x10];
    float limit;
    float scale;
};

struct Anim_149e0 {
    char pad0[0x20];
    Info_149e0 *info;
    void FUN_00225e00(float a, float b, float c, float d);
};

class Segmenter {
public:
    char FUN_000149e0(int index);

    char pad0[0x20];
    Table_149e0 *table;
    Anim_149e0 *anim;
    int index;
    float accum;
};

char Segmenter::FUN_000149e0(int idx)
{
    if (idx >= 8)
        return 0;
    index = idx;

    float lo = table->FUN_00069620(idx - 1);
    float span = table->FUN_00069620(idx) - lo;
    if (span <= 0.0f)
        return 0;

    float limit = anim->info->limit - 1.0f;
    float e = table->FUN_000695e0(idx - 1);
    if (e < 0.0f || e > limit)
        return 0;
    float f = table->FUN_000695e0(idx);
    if (f < 0.0f || f > limit)
        return 0;

    float acc = span + accum;
    accum = acc;
    if (acc < 0.0f)
        return 1;

    e = (span - acc) * ((f - e) / span) + e;
    anim->FUN_00225e00(-1.0f, ((f - e) / anim->info->scale) / acc, e, f);
    return 1;
}
