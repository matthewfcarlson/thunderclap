struct Vec3 {
    float x, y, z;
    void Subtract(Vec3* out, Vec3* rhs);
};
void Vec3::Subtract(Vec3* out, Vec3* rhs) {
    float dz = z - rhs->z;
    float dy = y - rhs->y;
    float dx = x - rhs->x;
    out->x = dx;
    out->y = dy;
    out->z = dz;
}