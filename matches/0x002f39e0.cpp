struct Block {
    unsigned int x[16];
};
void __fastcall Helper(Block*);
struct Obj {
    char pad[0x4c];
    Block a;
    Block b;
    unsigned char flag;
    int count;
    void Target(Block* p);
};
void Obj::Target(Block* p) {
    Block* dst = &a;
    Block* src = p;
    *dst = *src;
    b = a;
    Helper(&b);
    flag = 1;
    count = count + 1;
}
