typedef unsigned int u32;
class Obj { public: char pad[12]; void Work(u32); };
u32 __cdecl target(u32 p, u32 count, u32 arg) {
    if (count != 0) {
        Obj* q = (Obj*)p;
        u32 i = count;
        do {
            if (q) q->Work(arg);
            q = (Obj*)((char*)q + 12);
            i--;
        } while (i != 0);
        return (u32)q;
    }
    return p;
}
