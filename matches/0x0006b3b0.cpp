class Obj_6b3b0 {
  public:
    char pad[0x2c];
    int field;
    bool Set(int v);
};

bool Obj_6b3b0::Set(int v) {
    field = v;
    return true;
}
