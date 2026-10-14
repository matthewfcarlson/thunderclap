// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030ea10 @ 0x0030ea10
struct Vec3_30ea10 {
    unsigned int x, y, z;
};
struct Shape_30ea10 {
    Vec3_30ea10 v[5];
    unsigned int extra;
    void FUN_0030ea10(const Vec3_30ea10 *a, const Vec3_30ea10 *b, const Vec3_30ea10 *c, const Vec3_30ea10 *d, const Vec3_30ea10 *e, unsigned int f);
};

void Shape_30ea10::FUN_0030ea10(const Vec3_30ea10 *a, const Vec3_30ea10 *b, const Vec3_30ea10 *c, const Vec3_30ea10 *d, const Vec3_30ea10 *e, unsigned int f)
{
    v[0] = *a;
    v[1] = *b;
    v[2] = *c;
    v[3] = *d;
    v[4] = *e;
    extra = f;
}
