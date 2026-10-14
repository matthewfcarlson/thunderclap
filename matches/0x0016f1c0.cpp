class Obj_16f1c0 {
  public:
    char pad[0xc];
    int value;
    bool Set(int v);
};

bool Obj_16f1c0::Set(int v) {
    value = v;
    return true;
}
