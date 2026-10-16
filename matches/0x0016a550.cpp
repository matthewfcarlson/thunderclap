struct X {
    virtual bool test(void*);
    virtual void other();
};
extern int __cdecl check(void*, int, void*, void*, int);
extern int a, b;
bool X::test(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}