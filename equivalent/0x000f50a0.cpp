// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000f50a0 @ 0x000f50a0
namespace pure3d { class Scenegraph; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual T *Cast(void *);
};
}
}
typedef unsigned __int64 Key;
Key __cdecl FUN_0027b020(const char *name);

struct Controller {
    virtual void AddRef();
};

class Inventory {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Controller *Find(void *caster, Key key);
};
extern Inventory *DAT_004dd9cc;

class Slots {
public:
    char pad00[0x1a5c];
    Controller *controllers[2];
    char names[2][0x100];
    char pad_names[0x2105 - 0x1a5c - 8 - 0x200];
    char defaultName[1];
    void FUN_000f50a0(const char *assetName);
};

// Loads the named controller into the first free slot and remembers the default name next to it.
void Slots::FUN_000f50a0(const char *assetName)
{
    int i;
    for (i = 0; i < 2; ++i) {
        if (!controllers[i])
            break;
    }
    if (i >= 2)
        return;
    Inventory *inv = DAT_004dd9cc;
    Key key = FUN_0027b020(assetName);
    content::LoadInventory::DynamicCaster<pure3d::Scenegraph> caster;
    Controller *c = inv->Find(&caster, key);
    controllers[i] = c;
    if (!c)
        return;
    c->AddRef();
    char *dst = names[i];
    const char *src = defaultName;
    char ch;
    do {
        ch = *src++;
        *dst++ = ch;
    } while (ch);
}
