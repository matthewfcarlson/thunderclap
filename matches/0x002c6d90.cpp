struct V4_2c6d90 {
    short x, y, z, w;
    V4_2c6d90* Add(V4_2c6d90* out, V4_2c6d90* rhs);
};
V4_2c6d90* V4_2c6d90::Add(V4_2c6d90* out, V4_2c6d90* rhs) {
    V4_2c6d90 t;
    t.x = x + rhs->x;
    t.y = y + rhs->y;
    t.z = z + rhs->z;
    t.w = w + rhs->w;
    *out = t;
    return out;
}