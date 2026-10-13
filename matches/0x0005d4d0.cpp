class X {
  public:
    char* Get();
};
char* X::Get() {
    return (char*)this + 0x18;
}
