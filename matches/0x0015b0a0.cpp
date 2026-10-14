class Obj_15b0a0 {
    char pad[0x64];
    int value;

  public:
    bool Set(int x);
};

bool Obj_15b0a0::Set(int x) {
    value = x;
    return true;
}
