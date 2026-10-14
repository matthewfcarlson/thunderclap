class X_18ee80 {
  public:
    char pad[0x20];
    void* m;
    bool Set(void* v);
};
bool X_18ee80::Set(void* v) {
    m = v;
    return true;
}
