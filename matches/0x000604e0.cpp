class Obj_604e0 {
  public:
    char Pad[0x10];
    int Value;
    char SetSlot_000604e0(int a);
};

char Obj_604e0::SetSlot_000604e0(int a) {
    Value = a;
    return 1;
}
