class Child {
  public:
    void Run(int, int);
};
class Parent {
    char pad[0x88];
    Child* child;

  public:
    void Go(int a, int b);
};
void Parent::Go(int a, int b) {
    if (child)
        child->Run(a, b);
}