class Obj_192230 {
  public:
    char pad[0x30];
    int m30;
    bool Set(int v);
};

bool Obj_192230::Set(int v) {
    m30 = v;
    return true;
}
