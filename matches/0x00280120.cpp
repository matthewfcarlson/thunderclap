class Base {
  public:
    Base();
    virtual void v();
};
class EffectQueue : public Base {
  public:
    char pad[12];
    int one;
    char rest[0x60 - 0x14];
    virtual void v();
    EffectQueue();
};
EffectQueue::EffectQueue() {
    one = 1;
    int* p = (int*)(&rest[0x4c]);
    for (int i = 0; i < 100; ++i) {
        p[-18] = 0;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 24;
    }
}
