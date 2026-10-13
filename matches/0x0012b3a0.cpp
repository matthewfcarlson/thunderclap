class X {
  public:
    char pad[0x20];
    void* Get();
};
void* X::Get() {
    return (char*)this + 0x20;
}