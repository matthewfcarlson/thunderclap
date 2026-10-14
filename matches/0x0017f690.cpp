class Target_17f690 {
  public:
    char pad[12];
    int mValue;
    bool Set(int value);
};

bool Target_17f690::Set(int value) {
    mValue = value;
    return true;
}
