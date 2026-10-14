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
void __cdecl target(Obj_2192c0* p) {
    helper(p, p->value->a, p->value->count << 2, 0);
}