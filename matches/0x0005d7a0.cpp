class Obj_5d7a0 {
  public:
    char pad[0x48];
    int value;
    bool Set(int v);
};

bool Obj_5d7a0::Set(int v) {
    value = v;
    return true;
}
