// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002980b0 @ 0x002980b0
struct Vec3 { float x, y, z; };
struct Pair3 { Vec3 first, second; void FUN_002980b0(Vec3* out); };
void Pair3::FUN_002980b0(Vec3* out) {
    out->x = (first.x + second.x) * 0.5f;
    out->y = (first.y + second.y) * 0.5f;
    out->z = (first.z + second.z) * 0.5f;
}