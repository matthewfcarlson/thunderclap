class Obj_11c080 {
  public:
    char pad[0x30];
    int m30;
    bool Set(int x);
};

bool Obj_11c080::Set(int x) {
    m30 = x;
    return true;
}
