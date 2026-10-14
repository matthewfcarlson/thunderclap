class Obj_1aad10 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};

bool Obj_1aad10::Set(int x) {
    value = x;
    return true;
}
