class C {
  public:
    char pad[0x40];
    void* Get();
};
void* C::Get() {
    return (char*)this + 0x40;
}