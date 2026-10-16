struct X {
    virtual int test(void*);
    virtual void other();
};
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern int a, b;
int X::test(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}