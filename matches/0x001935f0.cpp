class T {
  public:
    char pad[0x100];
    char* Get();
};

char* T::Get() {
    return pad + 0x100;
}
