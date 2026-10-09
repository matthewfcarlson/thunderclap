struct V3 {
    float x, y, z;
};
struct F {
    void Interpolate(V3* a, V3* b, float t);
};
void F::Interpolate(V3* a, V3* b, float t) {
    V3* out = (V3*)this;
    out->x = (b->x - a->x) * t + a->x;
    out->y = (b->y - a->y) * t + a->y;
    out->z = (b->z - a->z) * t + a->z;
}