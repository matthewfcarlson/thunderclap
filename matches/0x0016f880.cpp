class Obj_16f880 {
  public:
    virtual void V0();
    char pad[8];
    void* mPtr;
    bool Fn(void* p);
};
bool Obj_16f880::Fn(void* p) {
    mPtr = p;
    return true;
}
