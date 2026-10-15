struct Obj {
    char pad[0x18];
    void* p;
};
struct X {
    char pad[4];
    Obj* obj;
    int state;
    void Run(int);
};
extern "C" void* __cdecl cast(void*, int, const void*, const void*, int);
extern "C" void __cdecl use(void*);
extern char a[], b[];
void X::Run(int) {
    if (state != 3) {
        void* p = obj->p;
        use(cast(p, 0, a, b, 0));
        if (state == 2)
            state = 0;
    }
}