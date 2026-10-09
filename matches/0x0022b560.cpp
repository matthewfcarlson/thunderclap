struct Vec4 {
    float x, y, z, w;
    Vec4* FlipIf(Vec4*);
};
extern double gZero;
Vec4* Vec4::FlipIf(Vec4* b) {
    if (b->w * w + b->z * z + b->y * y + b->x * x < gZero) {
        x = -x;
        y = -y;
        z = -z;
        w = -w;
    }
    return this;
}