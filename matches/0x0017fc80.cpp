class Obj {
  public:
    char pad[0x18];
    void* m18;
    bool Set(void* x);
};

bool Obj::Set(void* x) {
    m18 = x;
    return true;
}
