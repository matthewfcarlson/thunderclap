class Obj {
  public:
    void Work();
};
class Holder {
  public:
    int pad;
    Obj* obj;
    int Run(int a, int b);
};
int Holder::Run(int a, int b) {
    if (!obj)
        return -1;
    obj->Work();
    return 0;
}