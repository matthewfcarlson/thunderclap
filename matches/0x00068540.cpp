class Obj_68540 {
  public:
    char pad[0x14];
    void* value;
    bool Set(void* p);
};

bool Obj_68540::Set(void* p) {
    value = p;
    return true;
}
