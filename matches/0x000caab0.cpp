struct Ent;
struct Sub { void Tick(); };
struct Ent { void Prep(); char pad[0xec]; Sub* sub; };
struct Mgr { Ent* Find(char*); };
struct Mid { char pad[0xc]; Mgr* m; char pad2[0x10]; void* b; };
struct Self { char pad[0xc]; Mid* p; };
extern "C++" long long __cdecl FUN_002672f0(char*, int, int);
extern int __fastcall FUN_00024280(void*, long long);

void __fastcall FUN_000caab0(Self* self) {
    char* s = (char*)self + 0x264;
    int n = 8;
    do {
        if (*s) {
            void* b = self->p->b;
            long long v = FUN_002672f0(s, 0, 0);
            if (!FUN_00024280(b, v)) {
                Ent* e = self->p->m->Find(s);
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
