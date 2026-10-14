class Obj_5d800 {
  public:
    char pad[0x24];
    int value;
    bool Set(int x);
};

bool Obj_5d800::Set(int x) {
    value = x;
    return true;
}
