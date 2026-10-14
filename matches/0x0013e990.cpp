class X_13e990 {
  public:
    char pad[0x38];
    void* Get();
};
void* X_13e990::Get() {
    return (char*)this + 0x38;
}