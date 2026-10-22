// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001dca00 @ 0x001dca00
struct Item { char pad[0x18]; struct Object *object; char rest[0xc]; };
struct Object { char pad[0xec]; struct Inner *inner; };
struct Inner { int FUN_001d4e10(); };
struct CSPManager_1dca00 { char pad[0x608]; Item items[1]; int FUN_001dbfe0(void *key); int FUN_001dca00(void *key); };
int CSPManager_1dca00::FUN_001dca00(void *key) {
    int index = FUN_001dbfe0(key);
    if (index < 0) return 0;
    Object *obj = items[index].object;
    if (!obj) return 0;
    return obj->inner->FUN_001d4e10();
}