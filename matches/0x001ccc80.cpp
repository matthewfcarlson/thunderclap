class Target {
  public:
    char pad[0x11ac];
    int mValue;
    int GetValue();
};

int Target::GetValue() {
    return mValue;
}
