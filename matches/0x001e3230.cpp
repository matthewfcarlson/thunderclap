// FUN_001e3230 @ 0x001e3230
extern "C" int __cdecl strcmp(const char *a, const char *b);

struct Id_1e3230 {
    int lo, hi;
};

Id_1e3230 __cdecl FUN_00096d80(const char *name);

struct Config_1e3230 {
    char pad0[0x124];
    int value;
};

struct Owner_1e3230 {
    char pad0[0x20];
    Config_1e3230 *config;
};

struct Item_1e3230 {
    int FUN_001d6990();
    void FUN_001d8350(int value);
};

class CSPManager_1e3230 {
public:
    void FUN_001e3230(const char *name, const char *state);
    Item_1e3230 *FUN_001def30(const char *name);
    int FUN_001dbfe0(const char *name);
    void FUN_001e2ed0(int stateId, int idLo, int idHi);

    char pad0[0x1e830];
    Owner_1e3230 *owner;
};

void CSPManager_1e3230::FUN_001e3230(const char *name, const char *state) {
    Item_1e3230 *item = FUN_001def30(name);
    if (item != 0 && item->FUN_001d6990() == 7 && strcmp(state, "collected") == 0) {
        item->FUN_001d8350(owner->config->value);
    }
    Id_1e3230 id = FUN_00096d80(state);
    int stateId = FUN_001dbfe0(name);
    FUN_001e2ed0(stateId, id.lo, id.hi);
}
