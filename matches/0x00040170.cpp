class X_40170 {
  public:
    bool f(int);
    bool target();
};
bool X_40170::target() {
    bool bad = false;
    for (int i = 0; i < 8; i++)
        if (!f(i))
            bad = true;
    return !bad;
}