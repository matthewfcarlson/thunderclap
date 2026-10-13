class Obj {
  public:
    char pad[0x3c];
    int m3c;
    char FUN_001433f0(int value);
};
char Obj::FUN_001433f0(int value) {
    m3c = value;
    return 1;
}