class Obj_17f8b0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool Obj_17f8b0::Set(int x) {
    value = x;
    return true;
}
