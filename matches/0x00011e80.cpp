class A {
  public:
    char pad[0x10];
    char* Get();
};
char* A::Get() {
    return pad + 0x10;
}