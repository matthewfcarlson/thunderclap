struct V4 {
    short x, y, z, w;
    V4* Add(V4* out, V4* rhs);
};
V4* V4::Add(V4* out, V4* rhs) {
    V4 t;
    t.x = x + rhs->x;
    t.y = y + rhs->y;
    t.z = z + rhs->z;
    t.w = w + rhs->w;
    *out = t;
    return out;
}