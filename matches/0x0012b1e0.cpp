class X {
  public:
    char pad[0x18];
    void* Get();
};
void* X::Get() {
    return (char*)this + 0x18;
}