struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
    bool Copy(const Src* other);
};

bool Obj::Copy(const Src* other) {
    f14 = other->a;
    f18 = other->b;
    f1c = other->c;
    return true;
}