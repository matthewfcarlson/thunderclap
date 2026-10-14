class X_192430 {
  public:
    char pad[0x78];
    void* m78;
    bool Set(void* p);
};
bool X_192430::Set(void* p) {
    m78 = p;
    return true;
}
