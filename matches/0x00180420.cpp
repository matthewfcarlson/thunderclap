class Obj_180420 {
  public:
    char pad[0x14];
    int value;
    char SetDamage_00180420(int x);
};

char Obj_180420::SetDamage_00180420(int x) {
    value = x;
    return 1;
}
