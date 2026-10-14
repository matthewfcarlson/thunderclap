class Obj_16eae0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool Obj_16eae0::Set(int x) {
    value = x;
    return true;
}
