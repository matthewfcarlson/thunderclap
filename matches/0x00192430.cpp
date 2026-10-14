class X {
  public:
    char pad[0x78];
    void* m78;
    bool Set(void* p);
};
bool X::Set(void* p) {
    m78 = p;
    return true;
}
