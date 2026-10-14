class Obj_123840 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int v);
};

bool Obj_123840::Set(int v) {
    m10 = v;
    return true;
}
