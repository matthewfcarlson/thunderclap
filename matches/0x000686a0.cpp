class Obj_686a0 {
  public:
    char pad[0x6c];
    int field;
    bool Set(int v);
};

bool Obj_686a0::Set(int v) {
    field = v;
    return true;
}
