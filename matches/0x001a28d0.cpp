class Obj {
  public:
    char pad[0x108];
    unsigned char Get();
};
unsigned char Obj::Get() {
    return pad[0x108];
}
