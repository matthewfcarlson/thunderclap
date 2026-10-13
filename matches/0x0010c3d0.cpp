class X {
  public:
    virtual void f();
    char pad[0x14];
    void* m;
    void* Get();
};
void* X::Get() {
    return &m;
}
