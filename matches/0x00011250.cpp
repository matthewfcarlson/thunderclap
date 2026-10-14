struct Vec3_11250 {
    float x, y, z;
    void Subtract(Vec3_11250* out, Vec3_11250* rhs);
};
void Vec3_11250::Subtract(Vec3_11250* out, Vec3_11250* rhs) {
    float dz = z - rhs->z;
    float dy = y - rhs->y;
    float dx = x - rhs->x;
    out->x = dx;
    out->y = dy;
    out->z = dz;
}