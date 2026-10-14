struct Block_2f39e0 {
    unsigned int x[16];
};
void __fastcall Helper(Block_2f39e0*);
struct Obj_2f39e0 {
    char pad[0x4c];
    Block_2f39e0 a;
    Block_2f39e0 b;
    unsigned char flag;
    int count;
    void Target(Block_2f39e0* p);
};
void Obj_2f39e0::Target(Block_2f39e0* p) {
    Block_2f39e0* dst = &a;
    Block_2f39e0* src = p;
    *dst = *src;
    b = a;
    Helper(&b);
    flag = 1;
    count = count + 1;
}
