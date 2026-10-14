class Obj_11bb80 {
  public:
    char pad[0x2c];
    int value;
    bool Set(int x);
};

bool Obj_11bb80::Set(int x) {
    value = x;
    return true;
}
