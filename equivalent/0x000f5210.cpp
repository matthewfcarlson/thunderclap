// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000f5210 @ 0x000f5210
namespace pure3d { class CompositeDrawable; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual T *Cast(void *);
};
}
}
typedef unsigned __int64 Key_f5210;
Key_f5210 __cdecl FUN_0027b020(const char *name);

struct Controller_f5210 {
    virtual void AddRef();
};

class Inventory_f5210 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Controller_f5210 *Find(void *caster, Key_f5210 key);
};
extern Inventory_f5210 *DAT_004dd9cc;

class Slots_f5210 {
public:
    char pad00[0x1c6c];
    Controller_f5210 *controllers[2];
    char gap[0x200];
    char names[2][0x100];
    char pad_names[0x2105 - 0x1c6c - 8 - 0x200 - 0x200];
    char defaultName[1];
    void FUN_000f5210(const char *assetName);
};

// Loads the named controller into the first free slot and remembers the default name next to it.
void Slots_f5210::FUN_000f5210(const char *assetName)
{
    int i;
    for (i = 0; i < 2; ++i) {
        if (!controllers[i])
            break;
    }
    if (i >= 2)
        return;
    Inventory_f5210 *inv = DAT_004dd9cc;
    Key_f5210 key = FUN_0027b020(assetName);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Controller_f5210 *c = inv->Find(&caster, key);
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
