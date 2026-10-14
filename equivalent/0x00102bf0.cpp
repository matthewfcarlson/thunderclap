// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00102bf0 @ 0x00102bf0
// FUN_00102bf0: out = (target - origin), clamped to a maximum length
struct V3 {
    float x, y, z;
};

struct Anchor {
    void FUN_00059a50(V3 *out);
};

class Mover {
public:
    char pad00[0x10];
    Anchor *anchor;
    float FUN_000356b0();
};

extern "C" double __cdecl sqrt(double);

void __cdecl FUN_00102bf0(Mover *m, V3 *target, float speed, V3 *out)
{
    V3 origin;
    m->anchor->FUN_00059a50(&origin);
    out->x = target->x - origin.x;
    out->y = target->y - origin.y;
    out->z = target->z - origin.z;
    double root = sqrt(out->x * out->x + out->y * out->y + out->z * out->z);
    float len = (float)root;
    float t = (float)(root / speed);
    float limit = m->FUN_000356b0();
    float clamped = (t < limit) ? t : limit;
    float scale = clamped / len;
    out->x = scale * out->x;
    out->y = scale * out->y;
    out->z = scale * out->z;
}
