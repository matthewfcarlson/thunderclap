// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 16/16)
// FUN_000b8f20 @ 0x000b8f20
// cl-flags: /GS

class Manager_b8f20 { public: char pad[4]; };
Manager_b8f20 *__cdecl FUN_000fc1b0();

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
int FUN_00345804(const char *str, const char *fmt, ...);

struct TextEntry_b8f20 {
    void FUN_000f8500(const char *name, Manager_b8f20 *manager, char flag);
};

class FEObject {
public:
    virtual void vfunc_0();
};

FEObject *__cdecl FUN_000fc260(const char *name);

class TextSelector : public FEObject {
public:
    virtual void vfunc_1();
    char pad04[0x154 - 4];
    int selected;
    char pad158[0x1d58 - 0x158];
    void *field1d58;
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_1();
    char pad04[0x14];
    TextEntry_b8f20 entry;
};

class TextHost : public FEObject {
public:
    char pad04[0x6c - 4];
    void *locations[0x80];
    const char *names[0x80];
    void FUN_000b8f20();
};

class LocationLabel : public FEObject {
public:
    virtual void vfunc_1();
    void FUN_000e2a60(void *p);
};

void TextHost::FUN_000b8f20()
{
    char name[0x80];
    TextSelector *sel = dynamic_cast<TextSelector *>(FUN_000fc260("mission_selector"));
    if (sel != 0 && sel->field1d58 != 0) {
        int idx = sel->selected;
        if (idx >= 0 && idx < 0x80 && names[idx] != 0) {
            FUN_000964a0(name, 0x80, "%s", names[idx]);
            if (locations[idx] != 0) {
                LocationLabel *loc = dynamic_cast<LocationLabel *>(FUN_000fc260("location_label"));
                if (loc != 0)
                    loc->FUN_000e2a60(locations[idx]);
                TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260("description_label"));
                if (label != 0) {
                    int a = 0;
                    int b = 0;
                    char key[0x40];
                    FUN_00345804(name, "c%dm%d", &a, &b);
                    FUN_000964a0(key, 0x40, "TBS_MISSION_DESCRIPTION_C%02dM%02d", a, b);
                    label->entry.FUN_000f8500(key, FUN_000fc1b0(), 1);
                }
            }
        }
    }
}
