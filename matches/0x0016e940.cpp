class Obj_16e940 {
  public:
    char pad[0x58];
    int field;
    bool Set(int x);
};

bool Obj_16e940::Set(int x) {
    field = x;
    return true;
}
