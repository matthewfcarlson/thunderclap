#include "decls/address.h"
struct Ent_caab0;
struct Sub_caab0 {
    void Tick();
};
struct Ent_caab0 {
    void Prep();
    char pad[0xec];
    Sub_caab0* sub;
};
struct Mgr_caab0 {
    Ent_caab0* Find(char*);
};
struct Mid_caab0 {
    char pad[0xc];
    Mgr_caab0* m;
    char pad2[0x10];
    void* b;
};
struct Self_caab0 {
    char pad[0xc];
    Mid_caab0* p;
};
extern int __fastcall FUN_00024280(void*, long long);

void __fastcall FUN_000caab0(Self_caab0* self) {
    char* s = (char*)self + 0x264;
    int n = 8;
    do {
        if (*s) {
            void* b = self->p->b;
            long long v = FUN_002672f0(s, 0, 0);
            if (!FUN_00024280(b, v)) {
                Ent_caab0* e = self->p->m->Find(s);
                if (e) {
                    e->Prep();
                    e->sub->Tick();
                }
            }
        }
        s += 0x40;
    } while (--n);
    *(unsigned int*)((char*)self + 0x478) = 0;
    *(unsigned int*)((char*)self + 0x47c) = 0;
    *(unsigned int*)((char*)self + 0x480) = 0;
    *(unsigned int*)((char*)self + 0x484) = 0;
    *(unsigned int*)((char*)self + 0x488) = 0;
    *(unsigned int*)((char*)self + 0x48c) = 0;
}
