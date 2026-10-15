class Partition {
  public:
    virtual void f();
    int a;
    int x, y, z;
    Partition(const Partition& p) : x(p.x), y(p.y), z(p.z) {}
};
class Limb : public Partition {
  public:
    virtual void f();
    int b;
    int u, v, w;
    int tail;
    Limb(const Limb& p) : Partition(p), u(p.u), v(p.v), w(p.w) {}
};
Limb* __cdecl FUN_0027bc30(Limb* dest, int count, const Limb* src) {
    if (count) {
        int n = count;
        do {
            if (dest)
                dest->Limb::Limb(*src);
            ++dest;
        } while (--n);
        return dest;
    }
    return dest;
}