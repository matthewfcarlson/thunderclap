void Release(void*);
struct Obj_2f9cd0 {
    char pad[0x30];
    int a;
    int b;
    char pad2[8];
    int c;
    int d;
    void f();
};
void Obj_2f9cd0::f() {
    int x = c;
    d = x;
    if (x)
        Release((void*)x);
    x = a;
    b = x;
    if (x)
        Release((void*)x);
}