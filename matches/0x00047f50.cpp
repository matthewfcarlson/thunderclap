class Obj {
  public:
    char pad[0xc];
    void* mPointer;
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    mPointer = p;
    return true;
}
