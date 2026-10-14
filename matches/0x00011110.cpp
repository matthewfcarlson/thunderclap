struct Vec3_11110 {
    float x, y, z;
};
void __fastcall FUN_00011110(Vec3_11110* out, void*, const Vec3_11110* a, const Vec3_11110* b) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}