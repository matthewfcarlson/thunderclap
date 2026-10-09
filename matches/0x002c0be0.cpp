typedef unsigned int u32;
struct Obj { void ReleaseThing(); };
struct ImageLoader { u32 vptr; u32 pad[4]; Obj* mPtr; void Destroy(); };
void __cdecl DropThing(Obj*);
void ImageLoader::Destroy() {
    Obj* p = mPtr;
    vptr = 0x42eb0c;
    if (p) {
        p->ReleaseThing();
        DropThing(p);
    }
    vptr = 0x3f6098;
}