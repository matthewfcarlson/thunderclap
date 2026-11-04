class Obj_12b250 {
  public:
    char Pad[0x20];
    char Value;
    char SetThreatRespondOnlyOnce_0012b250(char c);
};

char Obj_12b250::SetThreatRespondOnlyOnce_0012b250(char c) {
    Value = c;
    return 1;
}