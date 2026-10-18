// FUN_000e5170 @ 0x000e5170
// FUN_000e5170 @ 0x000e5170: sets the enabled flag of the first menu entry with the given name, searching children recursively
extern "C" int __cdecl strcmp(const char *, const char *);

class Menu_e5170 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *GetName();
    char pad04[0xab8 - 4];
    char enabled;
    char padab9[3];
    Menu_e5170 *children[32];
    int childCount;
    void FUN_000e5170(const char *name, int value);
};

void Menu_e5170::FUN_000e5170(const char *name, int value)
{
    for (int i = 0; i < childCount; i++) {
        if (strcmp(children[i]->GetName(), name) != 0) {
            children[i]->FUN_000e5170(name, value);
        } else {
            children[i]->enabled = (char)value;
            return;
        }
    }
}
