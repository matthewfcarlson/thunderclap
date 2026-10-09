struct CUnlockable { char pad[0x20]; int value; };
struct Owner { int values[0x2ca]; };
extern int typeA;
extern int typeB;
extern void* FindType(void*, int, void*, void*, int);
int __fastcall target(Owner* self, void*, int id) {
    if (id >= 0x2ca && id <= 0x2dd) {
        CUnlockable* p = (CUnlockable*)FindType((void*)self->values[id], 0, &typeA, &typeB, 0);
        if (p) return p->value;
    }
    return 0;
}