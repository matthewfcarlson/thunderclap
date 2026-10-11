// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 7/8, incomplete)
// FUN_00080cd0 @ 0x00080cd0
struct Vec3 {
    float x, y, z;
};

struct Xform {
    char data[0x30];
    void FUN_0022cc90(Vec3 *v);
};

class Pusher {
public:
    char pad00[0x10];
    int state;
    char pad14[0x28 - 0x14];
    unsigned int flags;
    char pad2c[0x34 - 0x2c];
    Xform xform;
    Vec3 origin;
    char pad70[0xd0 - 0x70];
    Vec3 prev;
    Vec3 cur;
    void FUN_00080cd0(Vec3 *dir, bool keep);
};

void Pusher::FUN_00080cd0(Vec3 *dir, bool keep)
{
    Vec3 neg;
    neg.x = -dir->x;
    neg.y = -dir->y;
    neg.z = -dir->z;
    xform.FUN_0022cc90(&neg);

    state = 2;
    flags |= 2;
    if (keep)
        return;

    float a = cur.x - origin.x;
    float b = cur.y - origin.y;
    float c = cur.z - origin.z;
    float sum = b * dir->y + c * dir->z + a * dir->x;
    if (sum > 0.0f) {
        Vec3 old = cur;
        cur = prev;
        prev = old;
        flags |= 0x40;
        return;
    }
    if (a == 0.0f && c == 0.0f) {
        cur.x = origin.x;
        cur.y = origin.y;
        cur.z = origin.z;
        cur.x = cur.x - dir->x * 10.0f;
        cur.y = cur.y - dir->y * 10.0f;
        cur.z = cur.z - dir->z * 10.0f;
    }
    flags |= 0x40;
}
