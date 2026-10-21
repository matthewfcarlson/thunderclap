// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000a92c0 @ 0x000a92c0
struct Vec3_a92c0 { float x, y, z; };
struct Target_a92c0 { bool FUN_000382c0(Vec3_a92c0 *out); };
struct Owner_a92c0 { char pad[0x124]; Target_a92c0 *target; };
struct Context { char pad[0x20]; Owner_a92c0 *owner; };

class Offset_a92c0 {
public:
    char pad[0xe4];
    float dx, dy, dz;
    Vec3_a92c0 FUN_000a92c0(Context *ctx, Target_a92c0 *t);
};

Vec3_a92c0 Offset_a92c0::FUN_000a92c0(Context *ctx, Target_a92c0 *t)
{
    Vec3_a92c0 v;
    if (t != 0 && t->FUN_000382c0(&v)) {
        if (ctx->owner->target == t) {
            v.x += dx;
            v.y += dz;
            v.z += dz;
        }
        return v;
    }
    v.x = 0;
    v.y = 0;
    v.z = 0;
    return v;
}
