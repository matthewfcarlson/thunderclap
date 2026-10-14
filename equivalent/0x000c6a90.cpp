// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000c6a90 @ 0x000c6a90
struct Box { float x0, y0, z0, x1, y1, z1; };
struct Shape { char pad[0x14]; Box box; };
struct Size { unsigned x, y, z; };
union FloatBits { float f; unsigned u; };
void BoxExtent(Shape* s, Size* out) {
    if (!s) return;
    Box b = s->box;
    FloatBits d;
    d.f = b.x1 - b.x0; out->x = d.u & 0x7fffffff;
    d.f = b.y1 - b.y0; out->y = d.u & 0x7fffffff;
    d.f = b.z1 - b.z0; out->z = d.u & 0x7fffffff;
}
