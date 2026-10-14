class Obj_5d840 {
  public:
    char pad[0x40];
    int member;
    bool Set(int v);
};

bool Obj_5d840::Set(int v) {
    member = v;
    return true;
}
