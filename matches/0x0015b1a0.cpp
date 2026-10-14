class Obj_15b1a0 {
  public:
    char pad[0x90];
    int m90;
    bool Set(int x);
};

bool Obj_15b1a0::Set(int x) {
    m90 = x;
    return true;
}
