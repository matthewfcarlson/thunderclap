typedef unsigned int u32;
struct Obj {
    char pad[0x48];
};
extern Obj* __cdecl alloc_obj(u32, u32, u32, u32);
extern void __cdecl init_obj(u32, Obj*, int);
Obj* __cdecl target(u32 p) {
    Obj* x = alloc_obj(p, 0, 0, 0x48);
    init_obj(p, x, 9);
    *(u32*)(x->pad + 8) = 0;
    *(u32*)(x->pad + 0x28) = 0;
    *(u32*)(x->pad + 0x10) = 0;
    *(u32*)(x->pad + 0x34) = 0;
    *(u32*)(x->pad + 0xc) = 0;
    *(u32*)(x->pad + 0x2c) = 0;
    *(u32*)(x->pad + 0x30) = 0;
    *(u32*)(x->pad + 0x24) = 0;
    x->pad[0x44] = 0;
    *(u32*)(x->pad + 0x1c) = 0;
    x->pad[0x45] = 0;
    x->pad[0x46] = 0;
    x->pad[0x47] = 0;
    *(u32*)(x->pad + 0x14) = 0;
    *(u32*)(x->pad + 0x38) = 0;
    *(u32*)(x->pad + 0x18) = 0;
    *(u32*)(x->pad + 0x3c) = 0;
    *(u32*)(x->pad + 0x20) = 0;
    return x;
}