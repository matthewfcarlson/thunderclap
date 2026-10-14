class Obj_11c070 {
  public:
    char pad[0x2c];
    int value;
    bool Set(int x);
};

bool Obj_11c070::Set(int x) {
    value = x;
    return true;
}
