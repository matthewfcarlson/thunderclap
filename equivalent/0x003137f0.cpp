// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_003137f0 @ 0x003137f0
struct Vec3 {
    float x, y, z;
};

class Body {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 *position();
    char pad4[0x54 - 4];
    Vec3 normals[3];
};

void __stdcall FUN_003137f0(Body *body, Vec3 *pos, float a, float b, int index)
{
    int i = (index < 2) ? index + 1 : 0;
    Vec3 *p = body->position();
    float dx = pos->x - p->x;
    float dy = pos->y - p->y;
    float dz = pos->z - p->z;

    if (a > 0.0f) {
        const Vec3 *n = &body->normals[i];
        float dot = dz * n->z + dy * n->y + dx * n->x;
        float s;
        if (dot < 0.0f)
            s = -1.0f;
        else if (dot > 0.0f)
            s = 1.0f;
        else
            s = 0.0f;
        float t = -s * a;
        pos->x = t * n->x + pos->x;
        pos->y = t * n->y + pos->y;
        pos->z = t * n->z + pos->z;
    }
    if (b > 0.0f) {
        i = (i < 2) ? i + 1 : 0;
        const Vec3 *n = &body->normals[i];
        float dot = dz * n->z + dy * n->y + dx * n->x;
        float s;
        if (dot < 0.0f)
            s = -1.0f;
        else if (dot > 0.0f)
            s = 1.0f;
        else
            s = 0.0f;
        float t = -s * b;
        pos->x = t * n->x + pos->x;
        pos->y = t * n->y + pos->y;
        pos->z = t * n->z + pos->z;
    }
}
