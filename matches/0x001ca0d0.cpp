extern "C" void* __cdecl memset(void*, int, unsigned int);
struct Obj {
    int a, b, c, d, e;
    Obj();
};
Obj::Obj() {
    memset(this, 0, 20);
    a = 20;
    b = 14;
}