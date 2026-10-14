// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000b47b0 @ 0x000b47b0
// FUN_000b47b0 @ 0x000b47b0: sets the title and text of the fullscreen message widgets, then raises the screen
extern char DAT_0049dba4, DAT_0049f48c, DAT_0049f470;
struct Manager;
extern Manager *__cdecl FUN_000fc1b0();
extern void *__cdecl FUN_000fc260(const char *name);
struct Value {
    void FUN_000f8500(const char *text, Manager *manager, int flag);
};
struct Widget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void update();
    char pad04[20];
    Value value;
};
extern Widget *__cdecl FUN_00344e74(void *, int, char *, char *, int);
struct Screen {
    void FUN_001cc620(int);
};
struct Root {
    char pad00[44];
    Screen *screen;
};
extern Root *DAT_004dd700;

void __stdcall FUN_000b47b0(const char *title, const char *text)
{
    Widget *w = FUN_00344e74(FUN_000fc260("fullscreen_message_title"), 0, &DAT_0049dba4, &DAT_0049f48c, 0);
    if (w) {
        Manager *m = FUN_000fc1b0();
        w->value.FUN_000f8500(title, m, 1);
        w->update();
    }
    w = FUN_00344e74(FUN_000fc260("fullscreen_message_text"), 0, &DAT_0049dba4, &DAT_0049f470, 0);
    if (w) {
        Manager *m = FUN_000fc1b0();
        w->value.FUN_000f8500(text, m, 1);
        w->update();
    }
    DAT_004dd700->screen->FUN_001cc620(10);
}
