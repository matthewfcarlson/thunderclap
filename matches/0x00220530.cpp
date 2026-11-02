struct Obj {
    char pad[0x18];
    int a;
    int b;
};
extern "C" int __cdecl FUN_00220530(void * p) {
    return ((Obj *)p)->b = ((Obj *)p)->a;
}