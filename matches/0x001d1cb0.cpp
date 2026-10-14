typedef unsigned int uint;
struct Obj_1d1cb0 {
    char pad[8];
    void* m;
};
extern int __cdecl F12d70(void*);
extern void __cdecl F13380(void*, const char*, int);
extern void __cdecl F13600(void*, int);
extern int __cdecl F12f00(void*, int);
extern int __cdecl F12d80(void*, int);

bool __fastcall Target(Obj_1d1cb0* self) {
    int x = F12d70(self->m);
    F13380(self->m, "context", 7);
    F13600(self->m, 0xffffd8ef);
    int r = F12f00(self->m, -1);
    if (r != 5) {
        F12d80(self->m, x);
        return false;
    }
    return true;
}