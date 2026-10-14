class Obj_16f5e0 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};

bool Obj_16f5e0::Set(int x) {
    value = x;
    return true;
}
