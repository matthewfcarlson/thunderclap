// STATUS: must fail, also with EQUIV_ON=nanpayload (tools/equiv.py --wine level 3)
// (integ1, rev3 review of D39) deliberately wrong: a NaN v.x is returned with another payload (a payload bit flipped). A returned struct (sret) word is never a float store the rule may take.
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
            v.y += dy;
            v.z += dz;
        }
        if (v.x != v.x)
            { union { float f; unsigned u; } c_; c_.f = v.x; c_.u ^= 1; v.x = c_.f; }   // WRONG: another NaN payload
        return v;
    }
    v.x = 0;
    v.y = 0;
    v.z = 0;
    return v;
}
