extern char g1_24dd30[];
extern char g2_24dd30[];
extern char VT_24dd30[];
struct Obj_24dd30 {
    void* vptr;
    char d[0x44];
    void Init(char*, char*, int, int);
    void Finish();
};
extern void* Make(void*);
void* target() {
    Obj_24dd30 o;
    o.Init(g2_24dd30, g1_24dd30, 0x30, 4);
    o.vptr = VT_24dd30;
    void* p = Make(&o);
    o.Finish();
    return p;
}
