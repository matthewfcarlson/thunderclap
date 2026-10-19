class Obj {
  public:
    char pad[0x514];
    void* value;
    void Set(int);
};
struct ThisCall_001e9960 {
    void* FUN_001e9960(int);
};
void Obj::Set(int x) {
    void* p = ((ThisCall_001e9960*)(this))->FUN_001e9960(x);
    if (p)
        value = p;
}