extern const float kMinDist = 0.02f;
extern "C" double sqrt(double);
class Vec_1b3670 {
  public:
    float x, y, z;
    char pad[16];
    float limit;
    unsigned char Compare(const Vec_1b3670*);
};
unsigned char Vec_1b3670::Compare(const Vec_1b3670* other) {
    float dx = other->x - x, dy = other->y - y, dz = other->z - z;
    float a = dz * dz;
    a += dx * dx;
    a += dy * dy;
    a = (float)sqrt(a);
    if (a < kMinDist)
        a = kMinDist;
    return a <= limit;
}
