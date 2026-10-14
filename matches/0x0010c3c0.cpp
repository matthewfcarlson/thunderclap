class Obj_10c3c0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool Obj_10c3c0::Set(int x) {
    value = x;
    return true;
}
