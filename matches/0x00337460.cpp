class Child {
  public:
    char pad[0x81c];
    int value;
    int Check();
};
class Obj {
  public:
    char pad[0x5108];
    int result;
    Child* child;
    void Run();
};
void Obj::Run() {
    int r;
    int v;
    do {
        r = child->Check();
        v = child->value;
        result = v;
    } while (r == 0 && v == 0);
}