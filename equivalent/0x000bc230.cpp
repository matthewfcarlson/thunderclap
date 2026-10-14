// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_000bc230 @ 0x000bc230
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned n);

class Manager_bc230 { public: char pad[4]; };
extern "C" Manager_bc230 *__cdecl FUN_000fc1b0();

struct TextEntry_bc230 {
    void FUN_000f8500(const char *name, Manager_bc230 *manager, char flag);
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x10];
    int f14;
    TextEntry_bc230 entry;
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_4();
};
class TextWindow : public FEObject {
public:
    virtual void vfunc_4();
};
class TextButton : public FEObject {
public:
    virtual void vfunc_4();
};

extern "C" FEObject *__cdecl FUN_000fc260(const char *name);

class Widget_bc230 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void vfunc_19(int a);
};

class Hook_bc230 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Widget_bc230 *vfunc_3(const char *name);
};

extern "C" Hook_bc230 *__cdecl FUN_000fc3d0();

struct Sys_bc230 {
    void FUN_001cc620(int a);
};

struct Globals_bc230 {
    char pad[0x2c];
    Sys_bc230 *sys;
};

extern Globals_bc230 *DAT_004dd700;

class QuestionScreen {
public:
    char pad0[0x1c0c];
    char answer1[0x40];
    char answer2[0x40];
    void FUN_000bc230(const char *title, const char *text, const char *ans1, char *buf1, const char *ans2, char *buf2);
};

void QuestionScreen::FUN_000bc230(const char *title, const char *text, const char *ans1, char *buf1, const char *ans2, char *buf2)
{
    TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260("fullscreen_question_title"));
    if (label) {
        label->entry.FUN_000f8500(title, FUN_000fc1b0(), 1);
        label->vfunc_3();
    }
    TextWindow *win = dynamic_cast<TextWindow *>(FUN_000fc260("fullscreen_question_text"));
    if (win) {
        win->entry.FUN_000f8500(text, FUN_000fc1b0(), 1);
        win->vfunc_3();
    }
    TextButton *b1 = dynamic_cast<TextButton *>(FUN_000fc260("fullscreen_question_answer1"));
    if (b1) {
        b1->entry.FUN_000f8500(ans1, FUN_000fc1b0(), 1);
        // original calls through the previous object (win), not b1
        win->vfunc_3();
    }
    TextButton *b2 = dynamic_cast<TextButton *>(FUN_000fc260("fullscreen_question_answer2"));
    if (b2) {
        b2->entry.FUN_000f8500(ans2, FUN_000fc1b0(), 1);
        win->vfunc_3();
    }
    strncpy(answer1, buf1, 0x40);
    strncpy(answer2, buf2, 0x40);

    Widget_bc230 *w = FUN_000fc3d0()->vfunc_3("fullscreen_question");
    if (w) {
        FEObject *a = FUN_000fc260("fullscreen_question_answer1");
        if (a)
            w->vfunc_19(a->f14);
    }
    DAT_004dd700->sys->FUN_001cc620(11);
}
