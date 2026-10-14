class X_192240 {
  public:
    char pad[0x38];
    void* Get();
};
void* X_192240::Get() {
    return (char*)this + 0x38;
}
