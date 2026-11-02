// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 2/2)
// FUN_0021f300 @ 0x0021f300
// FUN_0021f300 @ 0x0021f300
struct Object { char pad[0x1c]; void *item; };
// equiv-conv: FUN_0021d830 eax esi
extern "C" void __cdecl FUN_0021d830(void *, void *);
extern "C" void __cdecl FUN_00220a50(void *, void *, int);
extern "C" void __cdecl FUN_0021e170(void *, void *, int);
// equiv-conv: FUN_0021f300 eax
extern "C" void FUN_0021f300(void *object) {
    void *item = ((Object *)object)->item;
    int values[6];
    FUN_0021d830((int *)(&values[1]), (Object *)((Object *)object));
    if (values[1] == 12) {
        FUN_00220a50(item, (int *)(&values[1]), 0);
    } else {
        values[0] = 0;
        FUN_0021e170((Object *)((Object *)object), (int *)values, 1);
    }
}
