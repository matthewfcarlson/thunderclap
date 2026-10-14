class Obj_6b340 {
  public:
    char pad[0x3c];
    int field;
    bool Set(int v);
};

bool Obj_6b340::Set(int v) {
    field = v;
    return true;
}
