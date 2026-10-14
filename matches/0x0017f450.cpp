class Obj {
  public:
    char pad[0x10];
    int m10;
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    m10 = (int)p;
    return true;
}