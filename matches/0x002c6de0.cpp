struct Vec {
    short x, y, z, w;
    void f(Vec* out, Vec* other);
};
void Vec::f(Vec* out, Vec* other) {
    Vec t;
    t.x = x - other->x;
    t.y = y - other->y;
    t.z = z - other->z;
    t.w = w - other->w;
    *(unsigned int*)out = *(unsigned int*)&t;
    *((unsigned int*)out + 1) = *((unsigned int*)&t + 1);
}