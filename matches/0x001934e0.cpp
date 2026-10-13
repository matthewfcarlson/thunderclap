class X {
  public:
    char pad[0xc8];
    void* Get();
};
void* X::Get() {
    return (char*)this + 0xc8;
}
