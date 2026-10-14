struct Vec3_1f6bc0 {
    float x, y, z;
};
void __fastcall f(Vec3_1f6bc0* self, void* edx, const Vec3_1f6bc0* a, float s, const Vec3_1f6bc0* b) {
    self->x = s * b->x + a->x;
    self->y = s * b->y + a->y;
    self->z = s * b->z + a->z;
}