class Obj_14cac0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Obj_14cac0::Set(int v) {
    value = v;
    return true;
}
