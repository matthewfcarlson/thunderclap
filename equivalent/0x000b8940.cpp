// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000b8940 @ 0x000b8940
#include "decls/data/game/global.h"

class FEObject { public: virtual void o0(); };
class TextSelector : public FEObject {
public:
    virtual void t1();
    virtual void t2();
    char pad04[0x150];
    int selection;
};
class TextWindow : public FEObject {
public:
    virtual void w1();
    virtual void w2();
    virtual void w3();
    void FUN_000e2a60(const char* text);
};

struct StoryText {
    const char* text;
    int a;
    int b;
};

FEObject* __cdecl FUN_000fc260(const char* name);

void FUN_000b8940() {
    TextSelector* list = dynamic_cast<TextSelector*>(FUN_000fc260("story_recap_list"));
    if (!list)
        return;
    TextWindow* window = dynamic_cast<TextWindow*>(FUN_000fc260("story_recap_text"));
    if (!window)
        return;
    window->FUN_000e2a60(((StoryText*)&DAT_00406740)[list->selection].text);
    window->w3();
}
