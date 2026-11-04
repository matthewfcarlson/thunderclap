class X_10c200 {
  public:
    char pad[0xc];
    int mValue;
    bool SetCompare_0010c200(int v);
};

bool X_10c200::SetCompare_0010c200(int v) {
    mValue = v;
    return true;
}
