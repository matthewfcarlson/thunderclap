class Target_146c70 {
  public:
    char pad[0x20];
    int mValue;
    bool SetX(int v);
};

bool Target_146c70::SetX(int v) {
    mValue = v;
    return true;
}
