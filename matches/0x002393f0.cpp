class C {
  public:
    char pad[0x24];
    char* Get();
};

char* C::Get() {
    return (char*)((int)this + 0x24);
}
