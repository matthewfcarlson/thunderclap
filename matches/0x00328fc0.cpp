class Obj_328fc0 {
  public:
    int a;
    int b;
    Obj_328fc0* Init();
    Obj_328fc0* Target(int, int);
};
Obj_328fc0* Obj_328fc0::Target(int p2, int p3) {
    a = p2;
    b = p3;
    Init();
    return this;
}
