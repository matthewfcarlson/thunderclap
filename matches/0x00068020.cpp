class Obj_68020 {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int x);
};

bool Obj_68020::Set(int x) {
    m1c = x;
    return true;
}
