// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 14/14)
// FUN_000ae8b0 @ 0x000ae8b0
extern "C" int strcmp(const char*, const char*);
extern float DAT_003f335c;

struct Item {
    char pad0[0x14];
    char name[1];           // 0x14
    void FUN_000b0740(const float* value);
};

struct List {
    char pad0[0x10];
    int count;              // 0x10
    Item* FUN_000ace20(int index);
};

class Owner {
public:
    int pad0;
    List* list;             // 0x04
    void FUN_000ae8b0(const char* name);
};

// Finds the list item with the given name and resets it.
void Owner::FUN_000ae8b0(const char* name)
{
    for (int i = 0; i < list->count; i++) {
        Item* item = list->FUN_000ace20(i);
        if (strcmp(item->name, name) == 0) {
            item->FUN_000b0740(&DAT_003f335c);
            return;
        }
    }
}
