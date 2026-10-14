class Obj_17f550 {
  public:
    char pad[0xc];
    void* value;
    bool Set(void* p);
};

bool Obj_17f550::Set(void* p) {
    value = p;
    return true;
}
