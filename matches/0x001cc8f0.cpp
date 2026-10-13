class Obj {
  public:
    char pad[0x11a0];
    char value;
    char Get();
};
char Obj::Get() {
    return value;
}