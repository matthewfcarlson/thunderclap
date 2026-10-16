class Child {
  public:
    void Fn(int, bool);
};
class Owner {
  public:
    char pad[0x4c];
    Child* child;
};
class X {
  public:
    int unused;
    Owner* owner;
    void Run(int p);
};
void X::Run(int p) {
    if (owner && owner->child)
        owner->child->Fn(0x1d, !p);
}