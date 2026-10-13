class X {
  public:
    char pad[0x38];
    void* Get();
};
void* X::Get() {
    return (char*)this + 0x38;
}
