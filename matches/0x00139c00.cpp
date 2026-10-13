class X {
  public:
    char pad[0x28];
    void* Get();
};
void* X::Get() {
    return (char*)this + 0x28;
}