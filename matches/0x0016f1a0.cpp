struct Src_16f1a0 {
    int a;
    int b;
    int c;
};

class Obj_16f1a0 {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    unsigned char Fn(Src_16f1a0* p);
};

unsigned char Obj_16f1a0::Fn(Src_16f1a0* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return 1;
}
