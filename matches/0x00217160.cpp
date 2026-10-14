class Ctx_217160 {
  public:
    char p[0x10];
    int a;
    char p2[4];
    int link;
    char p3[0x1c];
    int state;
    char p4[0x14];
    unsigned char bits;
};
class Param {
  public:
    char p[5];
    unsigned char flags;
    char p2[2];
    int data;
};
void FUN_00217100(int, Param*, int);
void FUN_00217160(int p1, Param* p2) {
    Ctx_217160* c = *(Ctx_217160**)((char*)p1 + 0x10);
    *(int*)p2 = c->link;
    c->link = (int)p2;
    unsigned char b = p2->flags;
    if ((b & 7) == 0) {
        if (c->state == 0) {
            p2->flags = b | 4;
            int* q = (int*)p2->data;
            if (q[0] >= 4) {
                int x = q[1];
                if ((*(unsigned char*)(x + 5) & 3) != 0 && (p2->flags & 4))
                    FUN_00217100(p1, p2, x);
            }
        } else
            p2->flags = (b & 0xf8) | *(unsigned char*)((char*)c + 0x14);
    }
}