class X {
  public:
    char pad[0x10];
    char* Get();
};

char* X::Get() {
    return (char*)((char*)this + 0x10);
}
