class C_1154e0 {
  public:
    char pad[0x18];
    void* mPtr;
    bool Set(void* p);
};

bool C_1154e0::Set(void* p) {
    mPtr = p;
    return true;
}