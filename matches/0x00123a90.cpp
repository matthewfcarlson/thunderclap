class Obj_123a90 {
  public:
    char pad[0x14];
    char m;
    char SetClearEveryFrame_00123a90(char x);
};

char Obj_123a90::SetClearEveryFrame_00123a90(char x) {
    m = x;
    return 1;
}
