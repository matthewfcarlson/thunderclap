struct V3_78710 {
    float x, y, z;
};
struct F_78710 {
    void Interpolate(V3_78710* a, V3_78710* b, float t);
};
void F_78710::Interpolate(V3_78710* a, V3_78710* b, float t) {
    V3_78710* out = (V3_78710*)this;
    out->x = (b->x - a->x) * t + a->x;
    out->y = (b->y - a->y) * t + a->y;
    out->z = (b->z - a->z) * t + a->z;
}