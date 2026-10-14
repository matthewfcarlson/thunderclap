struct Vec_2c6de0 {
    short x, y, z, w;
    void f(Vec_2c6de0* out, Vec_2c6de0* other);
};
void Vec_2c6de0::f(Vec_2c6de0* out, Vec_2c6de0* other) {
    Vec_2c6de0 t;
    t.x = x - other->x;
    t.y = y - other->y;
    t.z = z - other->z;
    t.w = w - other->w;
    *(unsigned int*)out = *(unsigned int*)&t;
    *((unsigned int*)out + 1) = *((unsigned int*)&t + 1);
}