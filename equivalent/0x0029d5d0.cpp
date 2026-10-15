// STATUS: equivalent (tools/equiv.py level 3: 10453 inputs, branch coverage 34/42, incomplete)
// FUN_0029d5d0 @ 0x0029d5d0
extern unsigned int DAT_004cf730;
extern float DAT_0042d618;
extern float DAT_003f32e0;

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Source {
    char pad0[0x11];
    unsigned char active;
    char pad12[2];
    unsigned int color;
    V3 pos;
    char pad24[0x3c];
    float scale;
    float falloff;
    void FUN_002c3d20(float *a, float *b, float *c);
};

struct SourceList {
    char pad0[0x10];
    int count;
    int total;
    Source **items;
};

struct Slot {
    float value;
    unsigned int color;
    float radiusSq;
    V3 dir;
    unsigned int flags;
    char pad1c[4];
};

struct SlotSet {
    SourceList *list;
    Slot *slots;
};

class Mixer {
public:
    char pad0[0x18];
    int hits;
    char pad1c[0x20];
    SlotSet *set;
    float FUN_0029d5d0(const V3 *pos, unsigned int mask);
};

float Mixer::FUN_0029d5d0(const V3 *pos, unsigned int mask)
{
    float sum = 0;
    for (int i = set->list->total - 1; i >= 0; i--) {
        SlotSet *s = set;
        SourceList *list = s->list;
        int off = i * 32;
        Source *src;
        if (i < list->count && (src = list->items[i]) != 0 && src->active != 0
            && (s->slots[i].flags & mask) == mask) {
            V3 d;
            d.x = pos->x - src->pos.x;
            d.y = pos->y - src->pos.y;
            d.z = pos->z - src->pos.z;
            Slot *slot = &s->slots[i];
            if (!(d.z * d.z + d.y * d.y + d.x * d.x >= slot->radiusSq)) {
                float unusedA, unusedB, factor;
                src->FUN_002c3d20(&unusedA, &unusedB, &factor);
                float len = d.FUN_0022d110();
                unsigned int color = DAT_004cf730;
                volatile float t = len * len * factor;
                volatile float z = src->falloff * src->falloff * factor * DAT_0042d618;
                if (z > 1.0f)
                    z = 1.0f;
                double v = DAT_003f32e0;
                if (t > DAT_003f32e0) {
                    unsigned int c = src->color;
                    int b0 = c & 0xff;
                    int b1 = (c >> 8) & 0xff;
                    int b2 = (c >> 16) & 0xff;
                    volatile float scale = z / t;
                    int mx = b1 >= b0 ? b1 : b0;
                    if (!(b2 < mx))
                        mx = b2;
                    v = (double)mx * scale;
                    int r = (int)(b0 * scale);
                    int g = (int)(b1 * scale);
                    int b = (int)(b2 * scale);
                    if (r < 0) r = 0; else if (r > 255) r = 255;
                    if (g < 0) g = 0; else if (g > 255) g = 255;
                    if (b < 0) b = 0; else if (b > 255) b = 255;
                    color = 0xff000000u | ((unsigned int)b << 16) | ((unsigned int)g << 8) | (unsigned int)r;
                }
                set->slots[i].color = color;
                set->slots[i].value = (float)v;
                set->slots[i].dir = d;
                if (v > DAT_003f32e0)
                    hits++;
                sum += v;
            } else {
                slot->value = 0;
            }
        } else {
            set->slots[i].value = 0;
        }
    }
    return sum;
}
