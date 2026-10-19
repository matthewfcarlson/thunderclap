// STATUS: equivalent (tools/equiv.py level 3: 18799 inputs, branch coverage 2/2)
// FUN_002e69a0 @ 0x002e69a0
// FUN_002e69a0 @ 0x002e69a0
struct Item { char pad[0x40]; void (__cdecl *callback)(Item *, void *); };
void FUN_002e6930(Item *item);
void __cdecl FUN_002e69a0(Item *item, void *context) {
    if (item->callback) item->callback(item, context);
    FUN_002e6930(item);
}
