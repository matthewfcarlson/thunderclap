class Obj {
  public:
    char pad[0x1e];
    unsigned char value;
    unsigned char Get();
};
unsigned char Obj::Get() {
    return value;
}
