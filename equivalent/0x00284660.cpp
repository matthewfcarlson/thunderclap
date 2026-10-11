// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00284660 @ 0x00284660
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat* a, const Quat* b, float t);
};

struct Vec3Pad {
    float x, y, z;
};

struct Matrix {
    char pad00[0x30];
    Vec3Pad pos;
    float pad3c;
};

void __cdecl FUN_0022b080(Quat* out, const Quat* a, const Quat* b);

struct Info {
    char pad00[0x10];
    unsigned int count;
};

class Pose {
public:
    char pad00[8];
    Info* info;
    char pad0c[4];
    Quat* quats;
    Matrix* mats;
    char pad18[8];
    char f20;
    char f21;
    char f22;
    char f23;

    bool FUN_00284660(Pose* other, float t, unsigned int only);
};

bool Pose::FUN_00284660(Pose* other, float t, unsigned int only)
{
    for (unsigned int i = 0; i < info->count; i++) {
        if (i != only) {
            quats[i].FUN_0022b750(&quats[i], &other->quats[i], t);
            Vec3Pad* d = &mats[i].pos;
            const Vec3Pad* s = &other->mats[i].pos;
            d->x = (s->x - d->x) * t + d->x;
            d->y = (s->y - d->y) * t + d->y;
            d->z = (s->z - d->z) * t + d->z;
        } else {
            Quat q;
            q.x = 0.0f;
            q.y = 0.0f;
            q.z = 0.0f;
            q.w = 1.0f;
            q.FUN_0022b750(&q, &other->quats[i], t);
            FUN_0022b080(&q, &q, &quats[i]);
            quats[i] = q;
            Vec3Pad* d = &mats[i].pos;
            const Vec3Pad* s = &other->mats[i].pos;
            d->x = t * s->x + d->x;
            d->y = t * s->y + d->y;
            d->z = t * s->z + d->z;
        }
    }
    f22 = 1;
    f23 = 1;
    f20 = 0;
    f21 = 1;
    return true;
}
