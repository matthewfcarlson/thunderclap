class Base {
  public:
    char pad[0x68];
    char* Get();
};
char* Base::Get() {
    return pad + 0x68;
}