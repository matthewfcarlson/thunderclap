class C {
  public:
    char* Get();
    char pad[0x40];
};
char* C::Get() {
    return (char*)this + 0x40;
}
