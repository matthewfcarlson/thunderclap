struct Info {
    int n;
    char pad[5];
    unsigned char type;
    unsigned char count;
};
void __cdecl FUN_002dd310(Info* p, unsigned char* data) {
    if (p->type == 0x10) {
        unsigned char* q = data;
        unsigned int n = p->count * p->n;
        for (; n > 0; --n) {
            unsigned char t = q[0];
            q[0] = q[1];
            q[1] = t;
            q += 2;
        }
    }
}