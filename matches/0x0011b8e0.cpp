class Obj {
  public:
    char pad[0x1d];
    unsigned char value;
    unsigned char Get();
};

unsigned char Obj::Get() {
    return value;
}
