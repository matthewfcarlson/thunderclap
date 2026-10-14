class X_12b3a0 {
  public:
    char pad[0x20];
    void* Get();
};
void* X_12b3a0::Get() {
    return (char*)this + 0x20;
}