// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 41/46, incomplete)
// FUN_000c1790 @ 0x000c1790
inline void* operator new(unsigned int, void* p) throw() { return p; }

extern "C" int strncmp(const char* a, const char* b, unsigned int n);
extern "C" int strcmp(const char* a, const char* b);
extern "C" char* strncpy(char* d, const char* s, unsigned int n);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern const char* DAT_0049f3b8;
extern char DAT_004dd839;

namespace pure3d { class TextureFont; }

struct Font {
    void FUN_00295250(int v);
};

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Loader_c1790 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Font* v3(content::LoadInventory::DynamicCaster<pure3d::TextureFont>* caster, unsigned __int64 hash);
    void FUN_002665a0();
};

struct Ui_c1790 {
    void FUN_000f7850();
    void FUN_000f89e0();
    void FUN_000f6fe0(int index);
};

struct Label_c1790 {
    void FUN_000f79a0(const unsigned short* s, int n);
};

struct DynamicLabel {
    char pad00[0x18];
    Label_c1790 label;
};

struct Panel_c1790 {
    void FUN_001bde50(int index);
    void FUN_001bde90();
    void FUN_001bdeb0();
};

extern Loader_c1790* DAT_004dd9c8;

int __cdecl FUN_00266da0(int mode);
Ui_c1790* __cdecl FUN_000fc1b0();
const char* __cdecl FUN_000f7120(int index);
void FUN_000964a0(char* buf, int size, const char* fmt, ...);
bool __cdecl FUN_000fc1c0(const char* path);
unsigned __int64 __cdecl FUN_0027b020(const char* name);
DynamicLabel* __cdecl FUN_000fc260(const char* name);

struct Frame_c1790 {
    content::LoadInventory::DynamicCaster<pure3d::TextureFont> caster;
    void* self;
    Ui_c1790* ui;
    int oldMode;
    char path[0x40];
    unsigned short text[0x100];
    unsigned int cookie;
};

class FrontEnd_c1790 {
public:
    char pad00[0x5c];
    Panel_c1790* panel;
    char pad60[0x1bc9 - 0x60];
    char lang[8];
    int FUN_000bc900(unsigned short* buf, int pos, const char* key, int idx);
    void FUN_000bc3c0(const char* path, Loader_c1790* loader, int zero);
    bool FUN_000c1790(const char* code);
};

bool FrontEnd_c1790::FUN_000c1790(const char* code)
{
    Frame_c1790 f;
    f.cookie = DAT_004d9968;
    f.self = this;
    f.oldMode = FUN_00266da0(0xe);
    f.ui = FUN_000fc1b0();
    if (strncmp(code, "en", 2) == 0 && DAT_004dd839)
        code = "uk";
    int idx = -1;
    for (int i = 0; i < 6; i++) {
        if (strncmp(code, FUN_000f7120(i), 2) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1)
        idx = 0;
    FUN_000964a0(f.path, 0x40, DAT_0049f3b8, code);
    if (FUN_000fc1c0(f.path)) {
        strncpy(lang, code, 3);
    } else {
        for (int i = 0; i < 6; i++) {
            FUN_000964a0(f.path, 0x40, DAT_0049f3b8, FUN_000f7120(i));
            if (FUN_000fc1c0(f.path)) {
                strncpy(lang, FUN_000f7120(i), 3);
                break;
            }
        }
    }
    if (panel)
        panel->FUN_001bde50(idx);
    DAT_004dd9c8->FUN_002665a0();
    if (f.ui)
        f.ui->FUN_000f7850();
    if (panel)
        panel->FUN_001bde90();
    DAT_004dd9c8->FUN_002665a0();
    FUN_000964a0(f.path, 0x40, "art/fonts_%s.p3d", lang);
    this->FUN_000bc3c0(f.path, DAT_004dd9c8, 0);
    const char* first;
    const char* second;
    if (strncmp("jp", lang, 2) == 0) {
        first = "font_msgothic";
        second = "font_eurostilesmall";
    } else {
        first = "font_futura_lt_med";
        second = "font_serpentine_lt_med";
    }
    {
        Loader_c1790* ld = DAT_004dd9c8;
        unsigned __int64 h = FUN_0027b020(first);
        new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::TextureFont>;
        ld->v3(&f.caster, h)->FUN_00295250(0xfa0);
    }
    {
        Loader_c1790* ld = DAT_004dd9c8;
        unsigned __int64 h = FUN_0027b020(second);
        new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::TextureFont>;
        ld->v3(&f.caster, h)->FUN_00295250(0xfa0);
    }
    Ui_c1790* ui = f.ui;
    if (ui) {
        ui->FUN_000f89e0();
        int i = 0;
        do {
            if (strcmp(lang, FUN_000f7120(i)) == 0)
                break;
            i++;
        } while (i < 6);
        if (i >= 6)
            i = 0;
        ui->FUN_000f6fe0(i);
    }
    if (panel)
        panel->FUN_001bdeb0();
    DynamicLabel* dl = FUN_000fc260("DynamicControlButtonLabel");
    if (dl) {
        Label_c1790* lbl = &dl->label;
        if (lbl) {
            int p = this->FUN_000bc900(f.text, 0, "TBS_MENU_ITEM_BONUS_FEATURES_SELECT", 0);
            this->FUN_000bc900(f.text, p, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            lbl->FUN_000f79a0(f.text, 0);
        }
    }
    FUN_00266da0(f.oldMode);
    __security_check_cookie(f.cookie);
    return true;
}
