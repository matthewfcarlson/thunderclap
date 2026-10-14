class X {
  public:
    char pad[0x20];
    void* m;
    bool Set(void* v);
};
bool X::Set(void* v) {
    m = v;
    return true;
}
