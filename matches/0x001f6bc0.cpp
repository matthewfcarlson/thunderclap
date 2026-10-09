struct Vec3 {
    float x, y, z;
};
void __fastcall f(Vec3* self, void* edx, const Vec3* a, float s, const Vec3* b) {
    self->x = s * b->x + a->x;
    self->y = s * b->y + a->y;
    self->z = s * b->z + a->z;
}