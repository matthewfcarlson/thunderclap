struct Src_17fef0 {
    int a;
    int b;
    int c;
};

class Obj_17fef0 {
  public:
    char pad[0x18];
    int x;
    int y;
    int z;
    bool Set(const Src_17fef0* p);
};

bool Obj_17fef0::Set(const Src_17fef0* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
