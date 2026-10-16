struct Vec3 {
    float x, y, z;
    Vec3& operator-=(const Vec3& v);
};
Vec3& Vec3::operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}