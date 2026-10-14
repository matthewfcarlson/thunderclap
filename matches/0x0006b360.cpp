class Obj_6b360 {
  public:
    char pad[0x40];
    int value;
    bool Set(int v);
};

bool Obj_6b360::Set(int v) {
    value = v;
    return true;
}
