class X_139b20 {
  public:
    char pad[0x38];
    void* Get();
};
void* X_139b20::Get() {
    return (char*)this + 0x38;
}
