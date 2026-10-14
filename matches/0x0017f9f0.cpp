class Obj_17f9f0 {
  public:
    char pad[0x30];
    int value;
    bool Set(int x);
};

bool Obj_17f9f0::Set(int x) {
    value = x;
    return true;
}
