class Obj_47f50 {
  public:
    char pad[0xc];
    void* mPointer;
    bool Set(void* p);
};

bool Obj_47f50::Set(void* p) {
    mPointer = p;
    return true;
}
