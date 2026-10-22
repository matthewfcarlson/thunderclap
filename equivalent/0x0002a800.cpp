// STATUS: equivalent (tools/equiv.py level 3: 1354 inputs, branch coverage 8/10, incomplete)
// FUN_0002a800 @ 0x0002a800
class Resource_2a800 {
public:
    virtual void vfunc_0();
    virtual void Release();
};

struct Child_2a800 {
    void FUN_00036d40(int arg);
};

struct Slot_2a800 {
    Child_2a800 *FUN_00059c10(void *item);
};

struct Context {
    char pad00[0x44];
    Slot_2a800 *slot;             // 0x44
};

struct Manager_2a800 {
    void FUN_001b4c40(Resource_2a800 *resource);
};

Manager_2a800 *__cdecl FUN_001b6580();

class ItemList_2a800 {
public:
    Context *context;       // 0x0
    char pad04[8];
    int count;              // 0xc
    void *items[69];        // 0x10
    Resource_2a800 *resource;     // 0x124
    void FUN_0002a4b0(int index, int arg);
    bool FUN_0002a800();
};

bool ItemList_2a800::FUN_0002a800()
{
    if (resource != 0) {
        resource->Release();
        resource = 0;
        Resource_2a800 * arg1_ = resource;
        FUN_001b6580()->FUN_001b4c40(arg1_);
    }

    for (int i = count - 1; i >= 0; i--) {
        context->slot->FUN_00059c10(items[i])->FUN_00036d40(0);
        FUN_0002a4b0(i, 0);
    }
    return true;
}
