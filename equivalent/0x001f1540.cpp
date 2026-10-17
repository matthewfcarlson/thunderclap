// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f1540 @ 0x001f1540
struct Item { void *FUN_001f0150(void *, void *, void *); };
struct Manager { void FUN_001ef260(void *); };
extern Manager *DAT_004e3710;
void *__cdecl FUN_0008d710(int, int);
void __stdcall FUN_001f1540(void *a, void *b, void *c) {
    if (a && b) {
        Manager *manager = DAT_004e3710;
        if (manager) {
            Item *item = (Item *)FUN_0008d710(0x20, 6);
            if (item)
                manager->FUN_001ef260(item->FUN_001f0150(a, b, c));
            else
                manager->FUN_001ef260(0);
        }
    }
}