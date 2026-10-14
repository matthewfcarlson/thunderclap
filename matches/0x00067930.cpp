struct Vec_67930 {
    float x, y, z;
};
void __fastcall FUN_00067930(Vec_67930* self, void*, Vec_67930* other, float t) {
    self->x = (other->x - self->x) * t + self->x;
    self->y = (other->y - self->y) * t + self->y;
    self->z = (other->z - self->z) * t + self->z;
}