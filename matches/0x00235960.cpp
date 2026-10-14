class Thing_235960 {
  public:
    char pad[0x10];
    char* Get();
};
char* Thing_235960::Get() {
    return (char*)this + 0x10;
}