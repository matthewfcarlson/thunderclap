class Ref_222660 {
  public:
    virtual void f0();
    virtual void Release();
};
class Puppet {
  public:
    virtual void f0();
    virtual void f1();
    char pad[0x60];
    Ref_222660* m64;
    int count;
    struct Entry {
        Ref_222660* ref;
        char pad[36];
    } items[1];
    void Tail();
    ~Puppet();
};
void Puppet::f0() {}
void Puppet::f1() {}
Puppet::~Puppet() {
    int n = count - 1;
    if (n >= 0) {
        Entry* p = items + n;
        int k = n + 1;
        do {
            p->ref->Release();
            --p;
            --k;
        } while (k != 0);
    }
    m64->Release();
    Tail();
}
