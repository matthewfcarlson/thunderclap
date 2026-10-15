struct Vec {
    float x, y, z;
};
class Plane {
  public:
    float x, y, z, d;
    Plane(const Vec* a, const Vec* b);
};
Plane::Plane(const Vec* a, const Vec* b) {
    x = a->x;
    y = a->y;
    z = a->z;
    d = -(b->z * z + b->y * y + b->x * x);
}