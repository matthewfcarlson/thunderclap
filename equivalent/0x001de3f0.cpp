// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 12/12)
// FUN_001de3f0 @ 0x001de3f0
class Obj_1de3f0 {
public:
    virtual void v0();
    virtual void Release();
    void FUN_001d7ff0();
};

class ObjList_1de3f0 {
public:
    char pad[0x1e620];
    Obj_1de3f0* items[128];    // 0x1e620
    int count;          // 0x1e820
    void FUN_001de3f0(Obj_1de3f0* target);
};

// Removes target from the list, shifting the following entries down.
void ObjList_1de3f0::FUN_001de3f0(Obj_1de3f0* target)
{
    bool found = false;
    int n = count;
    for (int i = 0; i < n; i++) {
        Obj_1de3f0* o = items[i];
        if (found) {
            items[i - 1] = o;
        } else if (o == target) {
            found = true;
            o->FUN_001d7ff0();
            if (items[i] != 0)
                items[i]->Release();
            items[i] = 0;
        }
    }
    items[count - 1] = 0;
    if (found)
        count--;
}
