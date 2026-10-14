class Obj_1aad70 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Obj_1aad70::Set(int v) {
    value = v;
    return true;
}
