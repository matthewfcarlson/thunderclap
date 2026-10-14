class Obj_60440 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool Obj_60440::Set(int x) {
    value = x;
    return true;
}
