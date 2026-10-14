class A_12e0a0 {
  public:
    bool Set(int value);

  private:
    char pad[12];
    int mValue;
};

bool A_12e0a0::Set(int value) {
    mValue = value;
    return true;
}
