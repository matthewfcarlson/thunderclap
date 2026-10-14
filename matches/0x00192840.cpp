class Obj_192840 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Obj_192840::Set(int v) {
    value = v;
    return true;
}
