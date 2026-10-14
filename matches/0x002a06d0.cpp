struct Result_2a06d0 {
    char pad[0x18];
};
struct Finder_2a06d0 {
    char pad[0x28];
    Result_2a06d0* find(int, int);
};
struct Root_2a06d0 {
    char pad[0x28];
    Finder_2a06d0* finder;
};
extern Root_2a06d0* gRoot_2a06d0;
extern int* gCompare;
struct Owner_2a06d0 {
    void act(Result_2a06d0*, int);
};
void __stdcall target(int arg) {
    Root_2a06d0* p = gRoot_2a06d0;
    Finder_2a06d0* f = p->finder;
    Result_2a06d0* r = f->find(arg, 0);
    if (r) {
        int* q = gCompare;
        if (*(int*)((char*)r + 0x14) == *q) {
            Owner_2a06d0* o = *(Owner_2a06d0**)((char*)r + 0x10);
            o->act(r, *(int*)((char*)r + 0xc));
        }
    }
}
