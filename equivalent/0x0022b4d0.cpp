// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022b4d0 @ 0x0022b4d0
struct Vec3 {
    float x, y, z;
};

struct Quat {
    float x, y, z, w;
    void Rotate(const Vec3 *v, Vec3 *out);
};

void __cdecl FUN_0022b080(Quat *out, const Quat *a, const Quat *b);

void Quat::Rotate(const Vec3 *v, Vec3 *out)
{
    Quat tmp;
    Quat vec;
    vec.x = v->x;
    vec.y = v->y;
    vec.z = v->z;
    vec.w = 0;
    FUN_0022b080(&tmp, this, &vec);
    vec.x = -x;
    vec.y = -y;
    vec.z = -z;
    vec.w = w;
    FUN_0022b080(&tmp, &tmp, &vec);
    out->x = tmp.x;
    out->y = tmp.y;
    out->z = tmp.z;
}
