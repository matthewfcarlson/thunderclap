class Obj_11bb40 {
  public:
    char pad[0x24];
    int value;
    bool Set(int v);
};

bool Obj_11bb40::Set(int v) {
    value = v;
    return true;
}
