class Vec3_34440 {
  public:
    float x, y, z;
    void Add(Vec3_34440* a, Vec3_34440* b);
};
void Vec3_34440::Add(Vec3_34440* a, Vec3_34440* b) {
    x = a->x + b->x;
    y = a->y + b->y;
    z = a->z + b->z;
}