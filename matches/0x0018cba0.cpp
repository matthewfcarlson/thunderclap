class Obj_18cba0 {
  public:
    char pad[0x10];
    int field;
    bool Set(int value);
};

bool Obj_18cba0::Set(int value) {
    field = value;
    return 1;
}
