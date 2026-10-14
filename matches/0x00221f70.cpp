class Obj2_221f70 {
  public:
    char pad[0x40];
    void callee1(int, int);
};
class Obj_221f70 {
  public:
    char pad[0x50];
    int state;
    void run(int, int);
    void callee2(int, int);
};
void Obj_221f70::run(int a, int b) {
    switch (state) {
    case 0:
    case 2:
        return callee2(a, b);
    case 1:
        return ((Obj2_221f70*)((char*)this + 0x40))->callee1(a, b);
    }
}
