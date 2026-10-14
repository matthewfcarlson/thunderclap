// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000f52a0 @ 0x000f52a0
namespace pure3d { class LightGroup; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual T *Cast(void *);
};
}
}
typedef unsigned __int64 Key_f52a0;
Key_f52a0 __cdecl FUN_0027b020(const char *name);

struct Controller_f52a0 {
    virtual void AddRef();
};

class Inventory_f52a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Controller_f52a0 *Find(void *caster, Key_f52a0 key);
};
extern Inventory_f52a0 *DAT_004dd9cc;

class Slots_f52a0 {
public:
    char pad00[0x1854];
    Controller_f52a0 *controllers[2];
    char names[2][0x100];
    char pad_names[0x2105 - 0x1854 - 8 - 0x200];
    char defaultName[1];
    void FUN_000f52a0(const char *assetName);
};

// Loads the named controller into the first free slot and remembers the default name next to it.
void Slots_f52a0::FUN_000f52a0(const char *assetName)
{
    int i;
    for (i = 0; i < 2; ++i) {
        if (!controllers[i])
            break;
    }
    if (i >= 2)
        return;
    Inventory_f52a0 *inv = DAT_004dd9cc;
    Key_f52a0 key = FUN_0027b020(assetName);
    content::LoadInventory::DynamicCaster<pure3d::LightGroup> caster;
    Controller_f52a0 *c = inv->Find(&caster, key);
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
