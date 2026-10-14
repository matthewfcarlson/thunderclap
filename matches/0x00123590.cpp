class X_123590 {
  public:
    char pad[0x18];
    void* Get();
};

void* X_123590::Get() {
    return (char*)this + 0x18;
}
