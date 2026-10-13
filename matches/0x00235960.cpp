class Thing {
  public:
    char pad[0x10];
    char* Get();
};
char* Thing::Get() {
    return (char*)this + 0x10;
}