class A {
  public:
    bool Set(int value);

  private:
    char pad[12];
    int mValue;
};

bool A::Set(int value) {
    mValue = value;
    return true;
}
