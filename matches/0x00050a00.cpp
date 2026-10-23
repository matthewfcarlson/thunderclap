struct X {
    virtual int test(void*);
    virtual void other();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_00491ca8, DAT_004929c8;
int X::test(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004929c8, 0) != 0;
}