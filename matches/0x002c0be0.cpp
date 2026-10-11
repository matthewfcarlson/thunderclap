extern "C" char DAT_003f6098[];
extern "C" char DAT_0042eb0c[];
typedef unsigned int u32;
struct Obj {
    void ReleaseThing();
};
struct ImageLoader {
    u32 vptr;
    u32 pad[4];
    Obj* mPtr;
    void Destroy();
};
void __cdecl DropThing(Obj*);
void ImageLoader::Destroy() {
    Obj* p = mPtr;
    vptr = ((int)DAT_0042eb0c);
    if (p) {
        p->ReleaseThing();
        DropThing(p);
    }
    vptr = ((int)DAT_003f6098);
}