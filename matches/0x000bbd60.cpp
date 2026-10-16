class Child {
  public:
    void Set(char);
};
class Parent {
  public:
    char pad[4];
    Child* child;
    void Fn(int value);
};
void Parent::Fn(int value) {
    if (child)
        child->Set(!value);
}