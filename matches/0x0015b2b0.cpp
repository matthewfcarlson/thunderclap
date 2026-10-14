class Obj_15b2b0 {
  public:
    char pad[0xc4];
    int value;
    bool Set(int v);
};

bool Obj_15b2b0::Set(int v) {
    value = v;
    return true;
}
