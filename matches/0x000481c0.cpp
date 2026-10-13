class Obj {
  public:
    char pad[12];
    void* mObj;
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    mObj = p;
    return true;
}