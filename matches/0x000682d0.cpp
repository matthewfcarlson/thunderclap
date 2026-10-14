class Obj_682d0 {
  public:
    char pad[0x24];
    int value;
    bool Set(int x);
};

bool Obj_682d0::Set(int x) {
    value = x;
    return 1;
}
