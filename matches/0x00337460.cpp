class Child_337460 {
  public:
    char pad[0x81c];
    int value;
    int Check();
};
class Obj_337460 {
  public:
    char pad[0x5108];
    int result;
    Child_337460* child;
    int Run();
};
int Obj_337460::Run() {
    int r;
    int v;
    do {
        r = child->Check();
        v = child->value;
        result = v;
    } while (r == 0 && v == 0);
    return r;
}