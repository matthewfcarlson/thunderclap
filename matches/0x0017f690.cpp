class Target {
  public:
    char pad[12];
    int mValue;
    bool Set(int value);
};

bool Target::Set(int value) {
    mValue = value;
    return true;
}
