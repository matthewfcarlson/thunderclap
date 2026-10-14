// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001fa8b0 @ 0x001fa8b0
// equiv-map: ??1IRefCount@core@@UAE@XZ = 0x0027afd0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void thunk_FUN_00267090(void *p) throw();

struct Name {
    char data[12];
    ~Name() throw();
};

class Child_1fa8b0 {
public:
    virtual void v0() throw();
    virtual void Release() throw();
};

void FUN_001f9f80(void *p) throw();

struct Task_1fa8b0 {
    char pad[0x18];
    Child_1fa8b0 *child;
    void FUN_00230f50(void (*callback)(void *), Task_1fa8b0 *self) throw();
};

namespace core {
class IRefCount {
public:
    virtual ~IRefCount() throw();
};
}

class CEncounterGenerator : public core::IRefCount {
public:
    class CEncounter {
    public:
        virtual void v0() throw();
        __forceinline ~CEncounter() throw() {}
        char pad04[0x30 - 4];
        Name name;
        char pad3c[0x58 - 0x3c];
    };
    virtual ~CEncounterGenerator() throw();
    char pad04[0x6e8 - 4];
    char encounterSlots[16][0x58];  // CEncounter objects, destroyed by hand below
    char pad_c68[4];
    Task_1fa8b0 *task;
};

CEncounterGenerator::~CEncounterGenerator() throw()
{
    Task_1fa8b0 *t = task;
    if (t != 0) {
        t->FUN_00230f50(FUN_001f9f80, t);
        t->child->Release();
        thunk_FUN_00267090(t);
    }
    task = 0;
    for (int i = 15; i >= 0; i--)
        ((CEncounter *)encounterSlots[i])->~CEncounter();
}
