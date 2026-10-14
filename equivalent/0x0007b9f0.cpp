// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0007b9f0 @ 0x0007b9f0
class Item_7b9f0 {
public:
    void FUN_00083d20(int v);
};
class Obj_7b9f0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Manager_7b9f0 {
public:
    char pad0[0x374c];
    Item_7b9f0* items[20];
    char pad379c[0x37ac - 0x379c];
    Obj_7b9f0* objs[20];
    int FUN_00079800(int key);
    void FUN_0007b9f0(int key);
};
void Manager_7b9f0::FUN_0007b9f0(int key) {
    int idx = FUN_00079800(key);
    if (idx == -1)
        return;
    items[idx]->FUN_00083d20(0x13);
    Item_7b9f0* item = items[idx];
    for (int i = 0; i < 20; i++) {
        if ((Item_7b9f0*)objs[i] == item) {
            if (objs[i] != 0) {
                objs[i]->vfunc_1();
                objs[i] = 0;
            }
            return;
        }
    }
}
