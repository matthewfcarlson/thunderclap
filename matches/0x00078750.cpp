struct Vec3_78750 {
    float x, y, z;
    void Add(Vec3_78750* out, Vec3_78750* other);
};
void Vec3_78750::Add(Vec3_78750* out, Vec3_78750* other) {
    float z = other->z + this->z;
    float y = other->y + this->y;
    float x = other->x + this->x;
    out->x = x;
    out->y = y;
    out->z = z;
}