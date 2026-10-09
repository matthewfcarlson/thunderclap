extern const float kMinDist = 0.02f;
extern "C" double sqrt(double);
class Vec {
  public:
    float x, y, z;
    char pad[16];
    float limit;
    unsigned char Compare(const Vec*);
};
unsigned char Vec::Compare(const Vec* other) {
    float dx = other->x - x, dy = other->y - y, dz = other->z - z;
    float a = dz * dz;
    a += dx * dx;
    a += dy * dy;
    a = (float)sqrt(a);
    if (a < kMinDist)
        a = kMinDist;
    return a <= limit;
}
