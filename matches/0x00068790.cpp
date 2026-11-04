class Obj_68790 {
  public:
    char pad[0x14];
    int value;
    char SetHint_00068790(int v);
};

char Obj_68790::SetHint_00068790(int v) {
    value = v;
    return 1;
}
