extern char g1[];
extern char g2[];
extern char VT[];
struct Obj {
    void* vptr;
    char d[0x44];
    void Init(char*, char*, int, int);
    void Finish();
};
extern void* Make(void*);
void* target() {
    Obj o;
    o.Init(g2, g1, 0x30, 4);
    o.vptr = VT;
    void* p = Make(&o);
    o.Finish();
    return p;
}
