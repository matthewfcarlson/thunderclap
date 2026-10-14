// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000a92c0 @ 0x000a92c0
struct Vec3 { float x, y, z; };
struct Target { bool FUN_000382c0(Vec3 *out); };
struct Owner { char pad[0x124]; Target *target; };
struct Context { char pad[0x20]; Owner *owner; };

class Offset {
public:
    char pad[0xe4];
    float dx, dy, dz;
    Vec3 FUN_000a92c0(Context *ctx, Target *t);
};

Vec3 Offset::FUN_000a92c0(Context *ctx, Target *t)
{
    Vec3 v;
    if (t != 0 && t->FUN_000382c0(&v)) {
        if (ctx->owner->target == t) {
            v.x += dx;
            v.y += dy;
            v.z += dz;
        }
        return v;
    }
    v.x = 0;
    v.y = 0;
    v.z = 0;
    return v;
}
