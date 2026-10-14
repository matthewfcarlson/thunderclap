// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000e8a90 @ 0x000e8a90
// FEDoAnimation constructor: reset the animation state and look the named entry up in the owning screen.
struct Entry_e8a90 {
    int f0;
    const char* name;
};

class Table_e8a90 {
public:
    Entry_e8a90* FUN_000e1dd0(const char* key);
};

class FEContainer {
public:
    virtual void v0();
};

class SharedTables {
public:
    char pad0[0x2078];
    Table_e8a90 table;
};

class FEScreenBase : public FEContainer {
public:
    SharedTables* shared;
    char pad8[0x9dc - 8];
    Table_e8a90 localTable;
};

class FEDoAnimation {
public:
    FEDoAnimation(FEContainer* container, const char* name);
    virtual void v0();
    char pad4[4];
    int field8;
    int fieldC;
    FEContainer* container;
    char flag14;
    char pad15[0x34 - 0x15];
    Entry_e8a90* entry;
    int field38;
    int field3c;
    int field40;
    float field44;
    float field48;
    float field4c;
    char flag50;
};

FEDoAnimation::FEDoAnimation(FEContainer* c, const char* name)
{
    field8 = -1;
    fieldC = -1;
    container = c;
    flag14 = 0;
    entry = 0;
    field38 = 0;
    field3c = 0;
    field40 = 0;
    field44 = -1.0f;
    field48 = -1.0f;
    field4c = 1.0f;
    flag50 = 1;

    FEScreenBase* screen = dynamic_cast<FEScreenBase*>(c);
    if (screen != 0) {
        Entry_e8a90* found = screen->localTable.FUN_000e1dd0(name);
        if (found == 0) {
            found = screen->shared->table.FUN_000e1dd0(name);
        }
        entry = found;
    }
}
