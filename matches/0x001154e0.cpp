class C {
  public:
    char pad[0x18];
    void* mPtr;
    bool Set(void* p);
};

bool C::Set(void* p) {
    mPtr = p;
    return true;
}