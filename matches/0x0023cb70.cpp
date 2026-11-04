class O_23cb70 {
  public:
    char pad[0xf];
    bool SetWin32_0023cb70(char v);
};
bool O_23cb70::SetWin32_0023cb70(char v) {
    ((char*)this)[0xf] = v;
    return true;
}