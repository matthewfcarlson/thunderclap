struct Ent_1b7290 {
    float w, x, y, z;
};
struct Buf_1b7290 {
    Ent_1b7290 e[1];
    Buf_1b7290* Init();
};
struct Obj_1b7290 {
    char pad[0x124];
    Buf_1b7290* buf;
    void Add(float, float, float, float);
};
extern void* __cdecl Alloc(unsigned);
void Obj_1b7290::Add(float a, float b, float c, float d) {
    if (!buf) {
        void* m = Alloc(0x504);
        buf = m ? ((Buf_1b7290*)m)->Init() : 0;
    }
    Buf_1b7290* p = buf;
    int* cnt = (int*)p;
    p->e[*cnt].x = a;
    p->e[*cnt].y = b;
    p->e[*cnt].z = c;
    p->e[*cnt + 1].w = d;
    *cnt = *cnt + 1;
}
