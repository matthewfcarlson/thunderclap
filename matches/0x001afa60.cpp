class Obj {
  public:
    char pad[0x3a];
    char value;
    char Get();
};

char Obj::Get() {
    return value;
}
