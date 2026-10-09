inline void* operator new(unsigned int, void* p) {
    return p;
}
class Partition {
  public:
    Partition() {}
    virtual void Destroy(int);
    char pad4[4];
    int a;
    int b;
    int c;
    int d;
};
class Owner {
  public:
    char pad0[4];
    Partition* mEnd;
    void Resize(Partition* stop, int count);
};
void Owner::Resize(Partition* stop, int count) {
    Partition* src = mEnd;
    Partition* dst = src + count;
    mEnd = dst;
    if (src != stop) {
        do {
            src = src - 1;
            dst = dst - 1;
            if (dst) {
                new (dst) Partition();
                dst->a = src->a;
                dst->b = src->b;
                dst->c = src->c;
            }
            src->Destroy(0);
        } while (src != stop);
    }
}
