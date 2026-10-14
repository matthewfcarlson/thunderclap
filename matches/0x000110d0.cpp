class V3_110d0 {
  public:
    float x, y, z;
    void Add(V3_110d0*);
};
void V3_110d0::Add(V3_110d0* other) {
    x += other->x;
    y += other->y;
    z += other->z;
}