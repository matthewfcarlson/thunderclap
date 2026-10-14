class Obj_17fea0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Obj_17fea0::Set(int v) {
    value = v;
    return true;
}
