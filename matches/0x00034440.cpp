class Vec3 {
  public:
    float x, y, z;
    void Add(Vec3* a, Vec3* b);
};
void Vec3::Add(Vec3* a, Vec3* b) {
    x = a->x + b->x;
    y = a->y + b->y;
    z = a->z + b->z;
}