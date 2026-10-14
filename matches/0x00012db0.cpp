class X_12db0 {
  public:
    char pad[0x18];
    void* Get();
};

void* X_12db0::Get() {
    return (char*)this + 0x18;
}
