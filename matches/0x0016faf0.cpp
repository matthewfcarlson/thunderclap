class X_16faf0 {
  public:
    char pad[0x18];
    void* Get();
};

void* X_16faf0::Get() {
    return (char*)this + 0x18;
}
