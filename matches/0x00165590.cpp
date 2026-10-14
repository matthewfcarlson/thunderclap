class Obj_165590 {
  public:
    char pad[0x10];
    void* m10;
    bool Set(void* p);
};

bool Obj_165590::Set(void* p) {
    m10 = p;
    return true;
}
