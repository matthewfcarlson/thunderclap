class Obj {
  public:
    void Do();
};
class Wrapper {
  public:
    int pad;
    Obj* obj;
    int Run(int a, int b);
};
int Wrapper::Run(int a, int b) {
    if (!obj)
        return -1;
    obj->Do();
    return 0;
}