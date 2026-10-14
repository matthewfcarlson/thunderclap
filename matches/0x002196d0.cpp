typedef unsigned int u32_2196d0;
struct Obj_2196d0 {
    char pad[0x48];
};
extern Obj_2196d0* __cdecl alloc_obj(u32_2196d0, u32_2196d0, u32_2196d0, u32_2196d0);
extern void __cdecl init_obj(u32_2196d0, Obj_2196d0*, int);
Obj_2196d0* __cdecl target(u32_2196d0 p) {
    Obj_2196d0* x = alloc_obj(p, 0, 0, 0x48);
    init_obj(p, x, 9);
    *(u32_2196d0*)(x->pad + 8) = 0;
    *(u32_2196d0*)(x->pad + 0x28) = 0;
    *(u32_2196d0*)(x->pad + 0x10) = 0;
    *(u32_2196d0*)(x->pad + 0x34) = 0;
    *(u32_2196d0*)(x->pad + 0xc) = 0;
    *(u32_2196d0*)(x->pad + 0x2c) = 0;
    *(u32_2196d0*)(x->pad + 0x30) = 0;
    *(u32_2196d0*)(x->pad + 0x24) = 0;
    x->pad[0x44] = 0;
    *(u32_2196d0*)(x->pad + 0x1c) = 0;
    x->pad[0x45] = 0;
    x->pad[0x46] = 0;
    x->pad[0x47] = 0;
    *(u32_2196d0*)(x->pad + 0x14) = 0;
    *(u32_2196d0*)(x->pad + 0x38) = 0;
    *(u32_2196d0*)(x->pad + 0x18) = 0;
    *(u32_2196d0*)(x->pad + 0x3c) = 0;
    *(u32_2196d0*)(x->pad + 0x20) = 0;
    return x;
}