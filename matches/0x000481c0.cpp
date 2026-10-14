class Obj_481c0 {
  public:
    char pad[12];
    void* mObj;
    bool Set(void* p);
};

bool Obj_481c0::Set(void* p) {
    mObj = p;
    return true;
}