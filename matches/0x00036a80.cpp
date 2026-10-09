struct A { char pad[0x10]; int value; };
struct B { char pad[0x11c]; int value; };
class Obj { public: char pad[0x124]; void* a; void* b; int f(int unused); };
int Obj::f(int unused) {
    int result = 0;
    void* p = a;
    if (p) return ((A*)p)->value;
    p = b;
    if (p) result = ((B*)p)->value;
    return result;
}