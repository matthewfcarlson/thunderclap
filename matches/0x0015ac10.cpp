class C_15ac10 {
  public:
    char pad[0x30];
    int flag;
    bool SetFlag(int x);
};

bool C_15ac10::SetFlag(int x) {
    flag = x;
    return true;
}
