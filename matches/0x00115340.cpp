class Obj_115340 {
  public:
    char pad[0x24];
    int value;
    bool Set(int v);
};

bool Obj_115340::Set(int v) {
    value = v;
    return true;
}