struct Vec3_306ef0 {
    float x, y, z;
};

class CollisionVolume_306ef0 {
  public:
    virtual void BaseFn();
    char m_pad[0x64];
    CollisionVolume_306ef0();
};

class CollisionRay : public CollisionVolume_306ef0 {
  public:
    virtual void RayFn();
    Vec3_306ef0 m_a; // 0x68
    Vec3_306ef0 m_b; // 0x74
    int m_c;  // 0x80
    CollisionRay(const Vec3_306ef0* a, const Vec3_306ef0* b, int c);
};

CollisionRay::CollisionRay(const Vec3_306ef0* a, const Vec3_306ef0* b, int c) {
    m_a.x = a->x;
    m_a.y = a->y;
    m_a.z = a->z;
    m_b.x = b->x;
    m_b.y = b->y;
    m_b.z = b->z;
    m_c = c;
}
