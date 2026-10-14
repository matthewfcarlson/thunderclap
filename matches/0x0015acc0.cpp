class C {
  public:
    char pad[0x70];
    char m;
    char* Get();
};
char* C::Get() {
    return &m;
}
