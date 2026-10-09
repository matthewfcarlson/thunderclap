struct Vec3 { float x,y,z; };
void __fastcall FUN_00011110(Vec3* out, void*, const Vec3* a, const Vec3* b) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}