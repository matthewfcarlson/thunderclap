struct Obj {
    char pad[8];
    void* m;
};
extern void __cdecl f(void*, unsigned int);
extern void __cdecl g(void*, int);
class Thing {
public:
    bool Run(unsigned int a, unsigned int b);
    char pad[8];
    void* m;
};
bool Thing::Run(unsigned int a, unsigned int b) {
    f(m, a);
    f(m, b);
    g(m, -3);
    return true;
}
