class Obj {
  public:
    char pad[0x38];
    unsigned char Get();
};

unsigned char Obj::Get() {
    return pad[0x38];
}
