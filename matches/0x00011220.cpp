struct Vec3 {
    float x, y, z;
    Vec3* Add(const Vec3* other);
};
Vec3* Vec3::Add(const Vec3* other) {
    x = x + other->x;
    y = y + other->y;
    z = z + other->z;
    return this;
}
