class Obj_61cb0 {
    char pad[0xc];
    void* mPtr;

  public:
    bool Set(void* p);
};

bool Obj_61cb0::Set(void* p) {
    mPtr = p;
    return true;
}
