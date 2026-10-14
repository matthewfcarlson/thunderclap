class X_10c3d0 {
  public:
    virtual void f();
    char pad[0x14];
    void* m;
    void* Get();
};
void* X_10c3d0::Get() {
    return &m;
}
