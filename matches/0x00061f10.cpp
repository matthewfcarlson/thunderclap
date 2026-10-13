class Obj {
  public:
    char pad[0x38];
    void* m38;
    bool Set(void* v);
};
bool Obj::Set(void* v) {
    m38 = v;
    return true;
}
