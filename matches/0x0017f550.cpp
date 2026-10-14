class Obj {
  public:
    char pad[0xc];
    void* value;
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    value = p;
    return true;
}
