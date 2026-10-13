class A {
  public:
    A* Get();
};

A* A::Get() {
    return this;
}
