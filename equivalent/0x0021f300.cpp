// STATUS: equivalent (tools/equiv.py level 3: 15821 inputs, branch coverage 2/2)
// FUN_0021f300 @ 0x0021f300
// FUN_0021f300 @ 0x0021f300
struct Object { char pad[0x1c]; void *item; };
// equiv-conv: FUN_0021d830 eax esi
void FUN_0021d830(int *value, Object *object);
void __cdecl FUN_00220a50(void *item, int *value, int flag);
void __cdecl FUN_0021e170(Object *object, int *value, int flag);
// equiv-conv: FUN_0021f300 eax
void FUN_0021f300(Object *object) {
    void *item = object->item;
    int values[5];
    FUN_0021d830(&values[1], object);
    if (values[1] == 12) {
        FUN_00220a50(item, &values[1], 0);
    } else {
        values[0] = 0;
        FUN_0021e170(object, values, 1);
    }
}
