struct Src_1925c0 {
    int a, b, c;
};

class Obj_1925c0 {
  public:
    char Set(Src_1925c0* p);
    char pad[18];
    int m14, m18, m1c;
};

char Obj_1925c0::Set(Src_1925c0* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return 1;
}