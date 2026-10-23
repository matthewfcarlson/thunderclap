extern char DAT_004e6330[];
extern char DAT_004e6338[];
extern char DAT_00429440[];
struct Obj_24dd30 {
    void* vptr;
    char d[0x44];
    void Init(char*, char*, int, int);
    void Finish();
};
extern void* FUN_00247530(void*);
void* target() {
    Obj_24dd30 o;
    o.Init(DAT_004e6338, DAT_004e6330, 0x30, 4);
    o.vptr = DAT_00429440;
    void* p = FUN_00247530(&o);
    o.Finish();
    return p;
}
