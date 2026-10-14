struct Vec4_22b560 {
    float x, y, z, w;
    Vec4_22b560* FlipIf(Vec4_22b560*);
};
extern double gZero_22b560;
Vec4_22b560* Vec4_22b560::FlipIf(Vec4_22b560* b) {
    if (b->w * w + b->z * z + b->y * y + b->x * x < gZero_22b560) {
        x = -x;
        y = -y;
        z = -z;
        w = -w;
    }
    return this;
}