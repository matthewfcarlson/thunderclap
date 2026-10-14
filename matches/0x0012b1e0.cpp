class X_12b1e0 {
  public:
    char pad[0x18];
    void* Get();
};
void* X_12b1e0::Get() {
    return (char*)this + 0x18;
}