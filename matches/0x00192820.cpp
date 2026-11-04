class Obj_192820 {
  public:
    char Pad[0x18];
    int value;
    char SetDecayScaler_00192820(int x);
};

char Obj_192820::SetDecayScaler_00192820(int x) {
    value = x;
    return 1;
}
