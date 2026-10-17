// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000962d0 @ 0x000962d0
struct Vec3 { float x, y, z; };
void __cdecl FUN_000962d0(Vec3* out, const Vec3* start, const Vec3* end, float t)
{
    float x = (end->x - start->x) * t + start->x;
    float y = (end->y - start->y) * t + start->y;
    float z = (end->z - start->z) * t + start->z;
    out->x = x;
    out->y = y;
    out->z = z;
}