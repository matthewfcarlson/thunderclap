class Target {
  public:
    char pad[0x20];
    int mValue;
    bool SetX(int v);
};

bool Target::SetX(int v) {
    mValue = v;
    return true;
}
