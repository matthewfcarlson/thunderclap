extern void* vA[];
extern void* vB[];
class Part_260e60 {
  public:
    void Fini() throw();
};
struct L_260e60 {
    char b[0x48];
    L_260e60* Init() throw();
    ~L_260e60() throw();
};
struct Target_260e60;
extern void FUN_00247550(L_260e60*, Target_260e60*);
struct Target_260e60 {
    void* vf;
    char pad[0x14];
    Part_260e60 part;
    Target_260e60* Dtor(unsigned char flag) throw();
};
Target_260e60* Target_260e60::Dtor(unsigned char flag) throw() {
    vf = vA;
    part.Fini();
    vf = vB;
    if (flag & 1) {
        L_260e60 l;
        FUN_00247550(l.Init(), this);
    }
    return this;
}
