class Obj_61e20 {
  public:
    char pad[0x90];
    int value;
    bool Set(int x);
};

bool Obj_61e20::Set(int x) {
    value = x;
    return true;
}
