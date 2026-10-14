class A_11e80 {
  public:
    char pad[0x10];
    char* Get();
};
char* A_11e80::Get() {
    return pad + 0x10;
}