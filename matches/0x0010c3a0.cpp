class Obj_10c3a0 {
  public:
    char pad[0xc];
    int value;
    bool Set(int v);
};

bool Obj_10c3a0::Set(int v) {
    value = v;
    return true;
}
