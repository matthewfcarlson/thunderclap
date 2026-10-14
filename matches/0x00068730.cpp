class Obj_68730 {
  public:
    char pad[0x90];
    int field;
    bool Set(int value);
};

bool Obj_68730::Set(int value) {
    field = value;
    return true;
}
