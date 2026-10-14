class Obj_15b1c0 {
  public:
    char pad[0x94];
    int value;
    bool Set(int v);
};

bool Obj_15b1c0::Set(int v) {
    value = v;
    return true;
}
