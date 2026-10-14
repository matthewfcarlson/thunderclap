struct Src_16fa40 {
    int a;
    int b;
    int c;
};

class Obj_16fa40 {
  public:
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
    bool Copy(const Src_16fa40* other);
};

bool Obj_16fa40::Copy(const Src_16fa40* other) {
    f14 = other->a;
    f18 = other->b;
    f1c = other->c;
    return true;
}