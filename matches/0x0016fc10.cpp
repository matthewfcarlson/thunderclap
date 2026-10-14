class Obj_16fc10 {
  public:
    char pad[0x40];
    int m40;
    bool Set(int v);
};

bool Obj_16fc10::Set(int v) {
    m40 = v;
    return true;
}