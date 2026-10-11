// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 14/14)
// FUN_002f8f10 @ 0x002f8f10
extern "C" double sqrt(double);
extern float DAT_00431754;
extern float DAT_004d2c5c;
extern float DAT_004d2c60;

struct Vec3 {
    float x, y, z;
};

struct Pos {
    char pad00[0x50];
    Vec3 p;
};

struct Shape {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    char pad04[0x28 - 4];
    Vec3 axis;
};

struct Body {
    char pad00[0x18];
    Pos *pos;
    char pad1c[4];
    Shape *shape;
    char pad24[0x68 - 0x24];
    char active;
};

struct FloatBits {
    float f;
};

class Pair {
public:
    Body *a;
    Body *b;
    float FUN_002f8f10(float t);
};

static float AxisDot(Shape *s, Vec3 *v)
{
    float d = v->z * s->axis.z + v->y * s->axis.y + v->x * s->axis.x;
    int bits = *(int *)&d & 0x7fffffff;
    return *(float *)&bits;
}

float Pair::FUN_002f8f10(float t)
{
    Vec3 v;
    if (a->active) {
        Pos *p = a->pos;
        v.x = p->p.x;
        v.y = p->p.y;
        v.z = p->p.z;
    } else {
        v.x = 0.0f;
        v.y = 0;
        v.z = 0;
    }
    if (b->active) {
        Pos *p = b->pos;
        v.x = v.x - p->p.x;
        v.y = v.y - p->p.y;
        v.z = v.z - p->p.z;
    }
    if (!(v.z * v.z + v.y * v.y + v.x * v.x > 1e-6f))
        return 0.0f;
    float len = (float)sqrt(v.z * v.z + v.y * v.y + v.x * v.x);
    float inv = 1.0f / len;
    v.x = v.x * inv;
    v.y = v.y * inv;
    v.z = v.z * inv;
    float dotA;
    Shape *sa = a->shape;
    if (sa->vfunc_6() == 8)
        dotA = 1000000000.0f;
    else
        dotA = AxisDot(sa, &v);
    float dotB;
    Shape *sb = b->shape;
    if (sb->vfunc_6() == 8)
        dotB = DAT_00431754;
    else
        dotB = AxisDot(sb, &v);
    float m = dotB;
    if (dotA < dotB)
        m = dotA;
    if (len * t > DAT_004d2c60 * m)
        return len * t * DAT_004d2c5c;
    return 0.0f;
}
