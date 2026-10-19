// STATUS: equivalent (tools/equiv.py level 3: 18281 inputs, branch coverage 4/4)
// FUN_000b9930 @ 0x000b9930
// cl-flags: /GS
// 0x000b9930: show the experience points value in its HUD label
extern int __cdecl _sprintf(char*, const char*, ...);
extern char DAT_0049dba4[];
extern char DAT_0049f48c[];
void* __cdecl FUN_000fc260(const char* name);
void* __cdecl FUN_00344e74(void* a, int b, const char* c, const char* d, int e);
int __stdcall FUN_000fc1b0();

struct Stats_b9930 {
    int FUN_00090110();
};

struct Text_b9930 {
    void FUN_000f8500(const char* text, int style, int extra);
};

struct Label_b9930 {
    char pad[0x18];
    Text_b9930 text;
};

class Hud_b9930 {
public:
    char pad[0x50];
    Stats_b9930* stats;
    void FUN_000b9930();
};

void Hud_b9930::FUN_000b9930()
{
    char buf[60];
    if (stats != 0) {
        Label_b9930* label = (Label_b9930*)FUN_00344e74(FUN_000fc260("experience_points_label"), 0, DAT_0049dba4, DAT_0049f48c, 0);
        if (label != 0) {
            _sprintf(buf, "%d", stats->FUN_00090110());
            label->text.FUN_000f8500(buf, FUN_000fc1b0(), 0);
        }
    }
}
