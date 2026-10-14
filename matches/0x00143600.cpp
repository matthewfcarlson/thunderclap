class Obj_143600 {
  public:
    char pad[0x54];
    int value;
    bool Set(int x);
};

bool Obj_143600::Set(int x) {
    value = x;
    return true;
}
