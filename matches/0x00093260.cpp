struct CUnlockable {
    char pad[0x20];
    int value;
};
struct Owner_93260 {
    int values[0x2ca];
};
extern int typeA_93260;
extern int typeB_93260;
extern void* FindType(void*, int, void*, void*, int);
int __fastcall target(Owner_93260* self, void*, int id) {
    if (id >= 0x2ca && id <= 0x2dd) {
        CUnlockable* p = (CUnlockable*)FindType((void*)self->values[id], 0, &typeA_93260, &typeB_93260, 0);
        if (p)
            return p->value;
    }
    return 0;
}