struct Vec3 { float x,y,z; void Add(Vec3* out, Vec3* other); };
void Vec3::Add(Vec3* out, Vec3* other) {
    float z = other->z + this->z;
    float y = other->y + this->y;
    float x = other->x + this->x;
    out->x = x;
    out->y = y;
    out->z = z;
}