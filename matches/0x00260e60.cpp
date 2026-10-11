extern void* vA[];
extern void* vB[];
class Part {
  public:
    void Fini() throw();
};
struct L {
    char b[0x48];
    L* Init() throw();
    ~L() throw();
};
struct Target;
extern void FUN_00247550(L*, Target*);
struct Target {
    void* vf;
    char pad[0x14];
    Part part;
    Target* Dtor(unsigned char flag) throw();
};
Target* Target::Dtor(unsigned char flag) throw() {
    vf = vA;
    part.Fini();
    vf = vB;
    if (flag & 1) {
        L l;
        FUN_00247550(l.Init(), this);
    }
    return this;
}
