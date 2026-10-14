// STATUS: equivalent (tools/equiv.py level 3: 238 inputs, branch coverage 12/12)
// FUN_000afaf0 @ 0x000afaf0
extern char DAT_004dda3d;

class Notifier {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void Reset(int flag);        // slot 6
};

class Source {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual Notifier *GetNotifier(unsigned int index);   // slot 16
};

struct Group {
    unsigned int count;      // 0x00
    char pad04[8];
    void *entries[8];        // 0x0c
    Source *owner;           // 0x2c
};

class Manager {
public:
    char pad00[8];
    char active;             // 0x08
    char pad09[7];
    int groupCount;          // 0x10
    Group *groups;           // 0x14
    void FUN_000af530(int group, unsigned int entry, int flag);
    void FUN_000afaf0();
};

void Manager::FUN_000afaf0() {
    if (!active)
        return;
    for (int g = 0; g < groupCount; g++) {
        for (unsigned int e = 0; e < groups[g].count; e++) {
            if (DAT_004dda3d)
                groups[g].owner->GetNotifier(e)->Reset(0);
            groups[g].entries[e] = 0;
            FUN_000af530(g, e, 0);
        }
    }
}
