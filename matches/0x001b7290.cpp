struct Ent {
    float w, x, y, z;
};
struct Buf {
    Ent e[1];
    Buf* Init();
};
struct Obj {
    char pad[0x124];
    Buf* buf;
    void Add(float, float, float, float);
};
extern void* __cdecl Alloc(unsigned);
void Obj::Add(float a, float b, float c, float d) {
    if (!buf) {
        void* m = Alloc(0x504);
        buf = m ? ((Buf*)m)->Init() : 0;
    }
    Buf* p = buf;
    int* cnt = (int*)p;
    p->e[*cnt].x = a;
    p->e[*cnt].y = b;
    p->e[*cnt].z = c;
    p->e[*cnt + 1].w = d;
    *cnt = *cnt + 1;
}
