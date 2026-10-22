extern void* vA[];
extern "C" void _ReadWriteBarrier();
class CollisionVolume_3060a0 {
  public:
    void* vptr;
    int m4;
    int m8, mc, m10, m14;
    char c18, c19;
    int m1c, m20, m24, m28, m2c, m30;
    float f;
    CollisionVolume_3060a0() throw();
};
CollisionVolume_3060a0::CollisionVolume_3060a0() throw() {
    m4 = 0;
    vptr = vA;
    _ReadWriteBarrier();
    m10 = 0;
    m14 = 0;
    c18 = 1;
    c19 = 0;
    _ReadWriteBarrier();
    m8 = -1;
    mc = -1;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    f = 1.0f;
}
