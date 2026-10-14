// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00302720 @ 0x00302720
// 0x00302720: update the blend factor of obj from the ratio of v to the summed weights of its two links
extern float DAT_004d2960;
extern float DAT_004d2f14;

struct Weight {
    char pad[0x80];
    float w;
};
struct Link_302720 {
    char pad[0x18];
    Weight* weight;
};
struct Obj_302720 {
    Link_302720* a;
    Link_302720* b;
    char pad[4];
    float blend;
};

class Limit {
public:
    char pad[0xc];
    float value;
    bool FUN_00302720(Obj_302720* o, float v);
};

bool Limit::FUN_00302720(Obj_302720* o, float v)
{
    if (v > value) {
        if ((o->b->weight->w + o->a->weight->w) * DAT_004d2960 == 0.0f) {
            o->blend = DAT_004d2f14;
            return false;
        }
        float ratio = v / ((o->b->weight->w + o->a->weight->w) * DAT_004d2960);
        if (ratio < DAT_004d2f14)
            o->blend = ratio;
        else
            o->blend = DAT_004d2f14;
        return false;
    }
    o->blend = 0.0f;
    return true;
}
