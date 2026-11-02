struct Inner_2192c0 {
    int a;
    int b;
    int count;
};
struct Obj_2192c0 {
    char pad[0x10];
    Inner_2192c0* value;
};
extern void __cdecl helper(Obj_2192c0*, int, int, int);
extern "C" void __cdecl FUN_002192c0(void * p) {
    helper(((Obj_2192c0 *)p), ((Obj_2192c0 *)p)->value->a, ((Obj_2192c0 *)p)->value->count << 2, 0);
}