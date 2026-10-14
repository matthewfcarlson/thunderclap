struct A_36a80 {
    char pad[0x10];
    int value;
};
struct B_36a80 {
    char pad[0x11c];
    int value;
};
class Obj_36a80 {
  public:
    char pad[0x124];
    void* a;
    void* b;
    int f(int unused);
};
int Obj_36a80::f(int unused) {
    int result = 0;
    void* p = a;
    if (p)
        return ((A_36a80*)p)->value;
    p = b;
    if (p)
        result = ((B_36a80*)p)->value;
    return result;
}