class Obj_294d70 {
  public:
    char pad[0x14];
    int a;
    int b;
    int c;
    int d;
    int e;
    void Init();
    Obj_294d70* Target();
};
Obj_294d70* Obj_294d70::Target() {
    Init();
    a = 0;
    b = 0;
    c = 0;
    d = 0x3f800000;
    e = 0x3f800000;
    return this;
}