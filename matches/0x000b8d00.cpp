// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 14/14)
// FUN_000b8d00 @ 0x000b8d00
// cl-flags: /GS
#include "decls/data/game/global.h"



class Manager_b8d00 { public: char pad[4]; };
Manager_b8d00 *__cdecl FUN_000fc1b0();

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct TextEntry_b8d00 {
    void FUN_000f8500(const char *name, Manager_b8d00 *manager, char flag);
};

class FEObject {
public:
    virtual void vfunc_0();
};

FEObject *__cdecl FUN_000fc260(const char *name);

class TextWindow : public FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14];
    TextEntry_b8d00 entry;
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14];
    TextEntry_b8d00 entry;
    char pad19[0x3c - 0x19];
    // Not reset per iteration: status values outside 1..3 reuse the previous colour (as the original does).
    unsigned int color;
};

struct Objectives {
    const char *FUN_001ccf50(int index);
    int FUN_001ccfa0(int index);
};

class ObjectivesScreen {
public:
    char pad0[0x38];
    Objectives *objectives;
    void FUN_000b8d00();
};

void ObjectivesScreen::FUN_000b8d00()
{
    // Not reset per iteration: status values outside 1..3 reuse the previous colour (as the original does).
    unsigned int color;
    if (objectives != 0) {
        for (int i = 0; i < 4; i++) {
            char buf[0x40];
            FUN_000964a0(buf, 0x40, "mission_objectives%d_text", i + 1);
            TextWindow *text = dynamic_cast<TextWindow *>(FUN_000fc260(buf));
            if (text != 0) {
                text->entry.FUN_000f8500(objectives->FUN_001ccf50(i), FUN_000fc1b0(), 1);
                text->vfunc_3();
            }
            FUN_000964a0(buf, 0x40, "mission_objectives%d_status", i + 1);
            TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260(buf));
            if (label != 0) {
                const char *name = ((const char*)&DAT_003f335c);
                switch (objectives->FUN_001ccfa0(i)) {
                case 1:
                    name = "TBS_MISSION_OBJECTIVE_STATUS_INCOMPLETE";
                    color = 0xffffffff;
                    break;
                case 2:
                    name = "TBS_MISSION_OBJECTIVE_STATUS_COMPLETE";
                    color = 0xff00ff00;
                    break;
                case 3:
                    name = "TBS_MISSION_OBJECTIVE_STATUS_FAILED";
                    color = 0xffff0000;
                    break;
                }
                label->entry.FUN_000f8500(name, FUN_000fc1b0(), 1);
                label->color = color;
                label->vfunc_3();
            }
        }
    }
}
