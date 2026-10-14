// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 67/68, incomplete)
// FUN_000b7ff0 @ 0x000b7ff0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class Manager_b7ff0 { public: char pad[4]; };

struct TextEntry_b7ff0 {
    void FUN_000f8500(const char* name, Manager_b7ff0* manager, char flag);
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x10];
    int f14;
    TextEntry_b7ff0 entry;
};

class TextWindow : public FEObject {
public:
    virtual void vfunc_4();
};

class TextSelector : public FEObject {
public:
    char pad1c[0x154 - 0x1c];
    int index;                  // 0x154
    virtual void vfunc_4();
};

int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);
FEObject* __cdecl FUN_000fc260(const char* name);

class HintMenu_b7ff0 {
public:
    void FUN_000b7ff0();

    char pad00[0x1a0c];
    int hintIds[1];             // 0x1a0c
};

void HintMenu_b7ff0::FUN_000b7ff0()
{
    unsigned int cookie = DAT_004d9968;
    char buf[0x40];

    TextWindow* text = dynamic_cast<TextWindow*>(FUN_000fc260("hint_text"));
    if (text) {
        TextSelector* selector = dynamic_cast<TextSelector*>(FUN_000fc260("hint_selector"));
        if (selector && selector->index >= 0) {
            int id = hintIds[selector->index];
            if (id >= 0x8e && id <= 0xde) {
                const char* name = 0;
                int base = -1;
                if (id >= 0x8f && id <= 0x94) { name = "EXPERIENCE"; base = 0x8f; }
                if (id >= 0x95 && id <= 0x98) { name = "COLLECTIBLES"; base = 0x95; }
                if (id >= 0x99 && id <= 0x9b) { name = "WEAPONIZATION"; base = 0x99; }
                if (id >= 0x9c && id <= 0xa1) { name = "FRSM"; base = 0x9c; }
                if (id >= 0xa2 && id <= 0xa4) { name = "CHURCH"; base = 0xa2; }
                if (id >= 0xa5 && id <= 0xa9) { name = "CAMERAS"; base = 0xa5; }
                if (id >= 0xaa && id <= 0xae) { name = "RAGE"; base = 0xaa; }
                if (id >= 0xaf && id <= 0xb3) { name = "MOVEMENT"; base = 0xaf; }
                if (id >= 0xb4 && id <= 0xc7) { name = "COMBAT"; base = 0xb4; }
                if (id >= 0xc8 && id <= 0xcb) { name = "NAVIGATION"; base = 0xc8; }
                if (id >= 0xcc && id <= 0xcf) { name = "HUD"; base = 0xcc; }
                if (id == 0xd0) { name = "WEAPON_PODS_C4M5"; base = 0xd0; }
                if (id >= 0xd1 && id <= 0xd8) { name = "TARGETING"; base = 0xd1; }
                if (id >= 0xd9 && id <= 0xdd) { name = "COMBO"; base = 0xd9; }

                if (base == 0xd0 && !(id >= 0xd9 && id <= 0xdd))
                    FUN_000964a0(buf, 0x40, "TBS_HINT_%s", name);
                else
                    FUN_000964a0(buf, 0x40, "TBS_HINT_%s_%d", name, id - base + 1);

                text->entry.FUN_000f8500(buf, 0, 1);
                text->vfunc_3();
            }
        }
    }
    __security_check_cookie(cookie);
}
