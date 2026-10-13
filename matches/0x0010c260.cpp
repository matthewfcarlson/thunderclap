class Obj {
  public:
    unsigned char Get();
    char pad[0x10];
    unsigned char m10;
};

unsigned char Obj::Get() {
    return m10;
}
