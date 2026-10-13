class Obj {
    char pad[0xc];
    void* mPtr;

  public:
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    mPtr = p;
    return true;
}
