class V3 {
  public:
    float x, y, z;
    void Add(V3*);
};
void V3::Add(V3* other) {
    x += other->x;
    y += other->y;
    z += other->z;
}