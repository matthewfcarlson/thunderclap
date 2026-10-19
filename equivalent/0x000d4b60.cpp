// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 62/62)
// FUN_000d4b60 @ 0x000d4b60
// cl-flags: /GS
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
struct Holder_d4b60 { unsigned int FUN_000f7d30(const void *s) throw(); void *FUN_000f7220(unsigned int id) throw(); };
struct Face7 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual float v7(); };
struct Slot_d4b60;
struct Face9 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float v9(Slot_d4b60 *s); };
struct Pobj { char pad00[0x24]; Face9 *tbl[1]; };
struct Elem_d4b60 { float v; float pad[3]; };
struct Lay_d4b60 { Pobj *p; char pad04[4]; Elem_d4b60 e[8]; int idx; char pad8c[4]; void FUN_000f7fe0(Holder_d4b60 *h) throw(); void FUN_000f78e0() throw(); float FUN_000d4950(const char *s, int fontIdx) throw(); };
struct Slot_d4b60 { unsigned short text[0x100]; unsigned int f200, f204, f208, f20c, f210, f214, f218, f21c, f220; int f224, f228, f22c, f230; char b234; char pad235[3]; int f238; };
struct Hud_d4b60 { void FUN_001ebd00(const char *a, const char *b) throw(); };
extern char DAT_004de500[0x100]; extern char DAT_004de300[0x200]; extern int DAT_004ddf98; extern char DAT_004dd8e8; extern unsigned int DAT_004ddfc0, DAT_004ddfc4, DAT_004ddfc8;
extern float DAT_004a06e0; extern unsigned int DAT_004d9968;
union U_4a06b4 { float f; unsigned int u; }; extern U_4a06b4 DAT_004a06b4;
int __cdecl FUN_000fc020(char *buf, int n, const void *fmt, ...) throw(); int __cdecl FUN_000fc000(char *buf, int n, const void *fmt, ...) throw(); int __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...) throw(); int __cdecl FUN_000fb720(const void *s) throw(); char __cdecl FUN_000fb6e0(const void *a, const void *b, int n) throw(); void __cdecl FUN_000fb690(void *dst, const void *src, int n) throw(); int __cdecl FUN_00294b80(const unsigned short *s) throw();
class HudMgr { public: char pad00[0xc]; Holder_d4b60 *f0c; Hud_d4b60 *f10; Slot_d4b60 slots[2]; char pad_after[0x7b4 - 0x14 - 2 * 0x23c]; float f7b4; char pad7b8[0x7c4 - 0x7b8]; char b7c4; char pad7c5[0x7d0 - 0x7c5]; unsigned int f7d0; char pad7d4[0x808 - 0x7d4]; float f808; Slot_d4b60 *FUN_000d4390() throw(); void FUN_000d4590(const char *s) throw(); int FUN_000d4ae0(const char *s, Lay_d4b60 *l, Face9 *f) throw(); void FUN_000d4400(int a, float f) throw(); void FUN_000d4b60(const char *a1, const void *a2, const void *a3, const void *a4, const void *a5, const void *a6, const void *a7); };
void HudMgr::FUN_000d4b60(const char *a1, const void *a2, const void *a3, const void *a4, const void *a5, const void *a6, const void *a7)
{
    if (!a1) return;
    Slot_d4b60 *message = FUN_000d4390();
    if (!message) return;
    strncpy(DAT_004de500, a1, 0xff);
    DAT_004de500[0xff] = 0;
    FUN_000d4590(DAT_004de500);
    Lay_d4b60 layout;
    char formatted[0x100];
    layout.FUN_000f7fe0(f0c);
    layout.e[layout.idx].v = f7b4 * f808;
    Holder_d4b60 *holder = f0c;
    void *translation = holder->FUN_000f7220(holder->FUN_000f7d30(a1));
    holder = f0c;
    if (holder->FUN_000f7220(holder->FUN_000f7d30(a2))) { holder = f0c; a2 = holder->FUN_000f7220(holder->FUN_000f7d30(a2)); }
    holder = f0c;
    if (holder->FUN_000f7220(holder->FUN_000f7d30(a3))) { holder = f0c; a3 = holder->FUN_000f7220(holder->FUN_000f7d30(a3)); }
    holder = f0c;
    if (holder->FUN_000f7220(holder->FUN_000f7d30(a4))) { holder = f0c; a4 = holder->FUN_000f7220(holder->FUN_000f7d30(a4)); }
    holder = f0c;
    if (holder->FUN_000f7220(holder->FUN_000f7d30(a5))) { holder = f0c; a5 = holder->FUN_000f7220(holder->FUN_000f7d30(a5)); }
    holder = f0c;
    if (holder->FUN_000f7220(holder->FUN_000f7d30(a6))) { holder = f0c; a6 = holder->FUN_000f7220(holder->FUN_000f7d30(a6)); }
    holder = f0c;
    if (holder->FUN_000f7220(holder->FUN_000f7d30(a7))) { holder = f0c; a7 = holder->FUN_000f7220(holder->FUN_000f7d30(a7)); }
    if (translation) FUN_000fc020(DAT_004de300, 0x100, translation, a2, a3, a4, a5, a6, a7);
    else {
        if (DAT_004dd8e8) FUN_00267760(formatted, 0x100, "[NITB] %s", a1);
        else FUN_00267760(formatted, 0x100, "%s", a1);
        FUN_000fc000(DAT_004de300, 0x100, formatted, a2, a3, a4, a5, a6, a7);
    }
    int lines = 1;
    if (layout.FUN_000d4950(DAT_004de300, DAT_004ddf98) > DAT_004a06e0)
        lines = FUN_000d4ae0(DAT_004de300, &layout, layout.p->tbl[DAT_004ddf98]);
    Slot_d4b60 *previous = 0;
    for (int i = 0; i < 2; ++i) {
        Slot_d4b60 *slot = &slots[i];
        if (slot->f22c == 0 && slot != message) {
            if (slot->f230 > 0) slot->b234 = 0;
            else if (slot->b234) previous = slot;
        }
    }
    bool duplicate = false;
    if (previous)
        duplicate = FUN_000fb6e0(DAT_004de300, previous, FUN_000fb720(previous)) != 0;
    if (!duplicate) {
        FUN_000fb690(message, DAT_004de300, FUN_000fb720(DAT_004de300) + 1);
        message->f220 = *(unsigned int *)&f808;
        message->f20c = DAT_004ddfc0;
        message->f210 = DAT_004ddfc4;
        message->f214 = DAT_004ddfc8;
        message->f200 = DAT_004ddfc0;
        message->f204 = message->f210;
        message->f208 = message->f214;
        message->f224 = 1;
        message->f228 = 2;
        message->f218 = 0;
        message->f21c = b7c4 ? DAT_004a06b4.u : f7d0;
        message->f22c = 0;
        message->f230 = 0;
        message->f238 = lines;
        if (lines >= 3) {
            for (int i = 0; i < 2; ++i) {
                Slot_d4b60 *slot = &slots[i];
                if (slot->f22c == 0 && slot != message) slot->b234 = 0;
            }
        } else if (previous) {
            if (previous->f238 + lines > 3) {
                int length = FUN_00294b80(previous->text);
                const unsigned short *end = previous->text + length;
                int count = 3 - message->f238;
                if (count > 0) {
                    do {
                        --end;
                        if (*end != 0xa) {
                            while (end >= previous->text) {
                                --end;
                                if (*end == 0xa) break;
                            }
                        }
                        --count;
                    } while (count);
                }
                const unsigned short *start = end + 1;
                int remaining = FUN_00294b80(start);
                memcpy(previous->text, start, remaining * 2 + 2);
            }
            Face9 *font = layout.p->tbl[DAT_004ddf98];
            volatile float scaledHeight = 14.0f * layout.e[layout.idx].v;
            float *elementHeight = &layout.e[layout.idx].v;
            float fontHeight = ((Face7 *)layout.p->tbl[0])->v7();
            volatile float ratio = *elementHeight / fontHeight;
            FUN_000d4400(message->f22c, font->v9(message) * ratio * 14.0f + scaledHeight * 0.1f);
            float remainingTime = *(float *)&previous->f21c - *(float *)&previous->f218;
            if (remainingTime > *(float *)&message->f21c) *(float *)&message->f21c = remainingTime;
            else *(float *)&message->f21c = *(float *)&message->f21c;
        }
        message->b234 = 1;
        f10->FUN_001ebd00("Message", "HUD_new_message");
    }
    layout.FUN_000f78e0();
}
