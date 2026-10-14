class Obj {
  public:
    char pad[0x10];
    void* m10;
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    m10 = p;
    return true;
}
