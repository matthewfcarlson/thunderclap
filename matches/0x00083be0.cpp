struct Vec {
    float x, y, z;
    void Cross(const Vec& a, const Vec& b);
};
void Vec::Cross(const Vec& a, const Vec& b) {
    float yy = b.x * a.z - b.z * a.x;
    float zz = ((const volatile Vec&)b).y * a.x - ((const volatile Vec&)b).x * a.y;
    float xx = b.z * a.y - b.y * a.z;
    x = xx;
    y = yy;
    z = zz;
}