void __cdecl f1(int);
class Child {
  public:
    void set(int);
};
class Obj {
  public:
    char a[0x10];
    int state;
    char b[0x1c];
    Child* ptr;
    char c[0x1cc8];
    int flag;
    void run(int);
    void f2(int);
};
void Obj::run(int arg) {
    if (state != 9) {
        state = 9;
        flag = 0;
        f1(arg);
        if (ptr) {
            ptr->set(6);
            f2(1);
        }
    }
}