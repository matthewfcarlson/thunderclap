// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0035a190 @ 0x0035a190
struct Vec3 {
    float x, y, z;
};

struct Box {
    Vec3 center;
    Vec3 axis[3];
    float extent[3];
};

// Clips a polygon against one plane (normal, d); updates *count.
extern void __cdecl FUN_00359a80(Vec3 *normal, float d, int *count, Vec3 *poly);

// Clips the triangle (a, b, c) against the six faces of an oriented box.
// Returns true when something is left (the polygon is in `out`, its vertex count in *count).
bool FUN_0035a190(Box *box, Vec3 *a, Vec3 *b, Vec3 *c, int *count, Vec3 *out)
{
    *count = 3;
    out[0] = *a;
    out[1] = *b;
    out[2] = *c;
    for (int s = -1; s <= 1; s += 2) {
        float sign = (float)s;
        for (int k = 0; k < 3; k++) {
            Vec3 n;
            n.x = sign * box->axis[k].x;
            n.y = sign * box->axis[k].y;
            n.z = sign * box->axis[k].z;
            FUN_00359a80(&n, n.x * box->center.x + n.y * box->center.y + n.z * box->center.z - box->extent[k], count, out);
        }
    }
    return *count > 0;
}
