class Obj {
  public:
    char pad[0x88];
    Obj* child;
    void Action(int a, int b);
    void Forward(int a, int b);
};
void Obj::Forward(int a, int b) {
    if (child)
        child->Action(a, b);
}