struct Obj { int DoThing(Obj*, int); };
extern Obj* __cdecl GetThing(int);
int __fastcall target(Obj* self, void*) {
    Obj* p = GetThing(0x2c);
    if (p) return p->DoThing(self, 0);
    return 0;
}