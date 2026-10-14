struct V4_22c310 {
    float x, y, z, w;
};
struct M_22c310 {
    float a[16];
    void Transform(const V4_22c310* in, V4_22c310* out);
};
void M_22c310::Transform(const V4_22c310* in, V4_22c310* out) {
    float e1 = a[1] * in->x + a[13] * in->w + a[9] * in->z + a[5] * in->y;
    float e2 = a[2] * in->x + a[14] * in->w + a[10] * in->z + a[6] * in->y;
    float e3 = a[3] * in->x + a[15] * in->w + a[11] * in->z + a[7] * in->y;
    float e4 = a[12] * in->w + a[8] * in->z + a[4] * in->y + a[0] * in->x;
    out->x = e4;
    out->y = e1;
    out->z = e2;
    out->w = e3;
}
