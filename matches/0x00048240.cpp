class Obj {
    char pad[0x14];
    int value;

  public:
    char SetMinVelocity_00048240(int x);
};
char Obj::SetMinVelocity_00048240(int x) {
    value = x;
    return 1;
}