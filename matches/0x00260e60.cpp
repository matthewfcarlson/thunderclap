extern void* vA[];
extern void* vB[];
class Part_260e60 {
  public:
    void Fini() throw();
};
struct TypeT_260e60 {
    char b[0x48];
    TypeT_260e60* Init() throw();
    ~TypeT_260e60() throw();
};
struct DynAttrT_260e60;
extern void FUN_00247550(TypeT_260e60*, DynAttrT_260e60*);
struct DynAttrT_260e60 {
    void* vf;
    char pad[0x14];
    Part_260e60 part;
    DynAttrT_260e60* Dtor(unsigned char flag) throw();
};
DynAttrT_260e60* DynAttrT_260e60::Dtor(unsigned char flag) throw() {
    vf = vA;
    part.Fini();
    vf = vB;
    if (flag & 1) {
        TypeT_260e60 l;
        FUN_00247550(l.Init(), this);
    }
    return this;
}
