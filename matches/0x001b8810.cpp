class Obj {
    char pad[0x33];

  public:
    unsigned char field;
    unsigned char Get();
};
unsigned char Obj::Get() {
    return field;
}