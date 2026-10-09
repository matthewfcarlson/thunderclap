// Same code shape as 0x000c5b40 (propagated; names are from that function)
extern int __fastcall g(void*);
struct S {
    void* p;
    volatile int a;
    char pad[0x3fc];
    volatile int count;
    int result;
    volatile int last;
    void f();
};
void S::f() {
    if (p) {
        count = 0;
        a = 0;
        *(int*)((char*)this + count * 8 + 8) = 0;
        result = g(p);
        last = 0;
    }
}