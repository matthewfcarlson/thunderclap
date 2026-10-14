class Obj_193870 {
  public:
    char pad[0x2c];
    int value;
    bool Set(int x);
};

bool Obj_193870::Set(int x) {
    value = x;
    return true;
}
