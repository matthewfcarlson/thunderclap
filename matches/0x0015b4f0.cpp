class Obj_15b4f0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Obj_15b4f0::Set(int v) {
    value = v;
    return true;
}
