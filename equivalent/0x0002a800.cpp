// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 8/10, incomplete)
// FUN_0002a800 @ 0x0002a800
class Resource {
public:
    virtual void vfunc_0();
    virtual void Release();
};

struct Child {
    void FUN_00036d40(int arg);
};

struct Slot {
    Child *FUN_00059c10(void *item);
};

struct Context {
    char pad00[0x44];
    Slot *slot;             // 0x44
};

struct Manager {
    void FUN_001b4c40(Resource *resource);
};

Manager *__cdecl FUN_001b6580();

class ItemList {
public:
    Context *context;       // 0x0
    char pad04[8];
    int count;              // 0xc
    void *items[69];        // 0x10
    Resource *resource;     // 0x124
    void FUN_0002a4b0(int index, int arg);
    bool FUN_0002a800();
};

bool ItemList::FUN_0002a800()
{
    if (resource != 0) {
        resource->Release();
        resource = 0;
        FUN_001b6580()->FUN_001b4c40(resource);
    }

    for (int i = count - 1; i >= 0; i--) {
        context->slot->FUN_00059c10(items[i])->FUN_00036d40(0);
        FUN_0002a4b0(i, 0);
    }
    return true;
}
