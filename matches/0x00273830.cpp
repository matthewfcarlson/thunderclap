class Interface_273830 {
  public:
    virtual void First();
    virtual void Second();
};
class Object {
  public:
    char pad[4];
    Interface_273830 iface;
    char pad2[0x0c];
    int value;
};
class Holder_273830 {
  public:
    char pad[8];
    Object* obj;
    int Run(int a, int b);
};
int Holder_273830::Run(int a, int b) {
    obj->iface.First();
    obj->value = b;
    obj->iface.Second();
    return a;
}