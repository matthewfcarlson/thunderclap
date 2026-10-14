class Obj {
  public:
    virtual void V0();
    char pad[8];
    void* mPtr;
    bool Fn(void* p);
};
bool Obj::Fn(void* p) {
    mPtr = p;
    return true;
}
