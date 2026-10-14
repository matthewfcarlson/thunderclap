// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000c6a90 @ 0x000c6a90
struct Box_c6a90 { float x0, y0, z0, x1, y1, z1; };
struct Shape_c6a90 { char pad[0x14]; Box_c6a90 box; };
struct Size { unsigned x, y, z; };
union FloatBits_c6a90 { float f; unsigned u; };
void BoxExtent(Shape_c6a90* s, Size* out) {
    if (!s) return;
    Box_c6a90 b = s->box;
    FloatBits_c6a90 d;
    d.f = b.x1 - b.x0; out->x = d.u & 0x7fffffff;
    d.f = b.y1 - b.y0; out->y = d.u & 0x7fffffff;
    d.f = b.z1 - b.z0; out->z = d.u & 0x7fffffff;
}
