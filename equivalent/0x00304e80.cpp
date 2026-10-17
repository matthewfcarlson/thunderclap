// STATUS: equivalent (tools/equiv.py level 3: 720 inputs, branch coverage 6/6)
// FUN_00304e80 @ 0x00304e80
extern "C" void __cdecl FUN_0008d340(void *);
struct Item { char pad[8]; void *allocation; char tail[4]; };
struct Owner { char pad0[4]; Item *items; char pad1[8]; void *other; void FUN_00304e80(); };
void Owner::FUN_00304e80() {
    Item *const entries = items;
    if (entries) {
        int *const header = (int *)((char *)entries - 4);
        const int count = *header;
        for (int i = count - 1; i >= 0; --i)
            FUN_0008d340(entries[i].allocation);
        FUN_0008d340(header);
    }
    FUN_0008d340(other);
}