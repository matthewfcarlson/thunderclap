class Obj_17fc80 {
  public:
    char pad[0x18];
    void* m18;
    bool Set(void* x);
};

bool Obj_17fc80::Set(void* x) {
    m18 = x;
    return true;
}
