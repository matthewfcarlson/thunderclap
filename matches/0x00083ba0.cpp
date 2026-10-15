struct Vec {
    float x, y, z;
    void Cross(const Vec* a);
};
void Vec::Cross(const Vec* a) {
    float yy = a->x * z - a->z * x;
    float zz = a->y * x - ((volatile const float*)a)[0] * y;
    float xx = a->z * y - a->y * z;
    x = xx;
    y = yy;
    z = zz;
}