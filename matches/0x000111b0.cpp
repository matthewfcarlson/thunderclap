struct V {
    float x, y, z;
    void Cross(const V& a, const volatile V& b);
};
void V::Cross(const V& a, const volatile V& b) {
    float yy = b.x * a.z - b.z * a.x;
    float zz = b.y * a.x - b.x * a.y;
    float xx = b.z * a.y - b.y * a.z;
    x = xx;
    y = yy;
    z = zz;
}