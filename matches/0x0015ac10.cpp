class C {
  public:
    char pad[0x30];
    int flag;
    bool SetFlag(int x);
};

bool C::SetFlag(int x) {
    flag = x;
    return true;
}
