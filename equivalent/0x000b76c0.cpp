// STATUS: equivalent (tools/equiv.py level 3: 19939 inputs, branch coverage 10/10)
// FUN_000b76c0 @ 0x000b76c0
// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
#include "gen/owners.h"
static inline int memcmp_inline(const void *a, const void *b, unsigned n)
{
    const unsigned char *p = (const unsigned char *)a;
    const unsigned char *q = (const unsigned char *)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}

class FEObject_b76c0 {
public:
    virtual void v0();
};
class TextButton_b76c0 : public FEObject_b76c0 {
public:
    char pad04[0x141 - 4];
    char complete;
};

struct Counter_b76c0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Stats_b76c0 {
    char pad0[0x80];
    Counter_b76c0 counter;
    int FUN_0008a2d0();
};

FEObject_b76c0 *__cdecl FUN_000fc260(const char *name);

class PauseScreen {
public:
    char pad0[0x34];
    Stats_b76c0 *stats;
    void FUN_000b76c0();
};

// Marks the pause menu's save button as "complete" for save states 1..7.
void PauseScreen::FUN_000b76c0()
{
    TextButton_b76c0 *button = dynamic_cast<TextButton_b76c0 *>(FUN_000fc260("pause_save"));
    if (button) {
        int state = stats->counter.FUN_00088fa0();
        int other = stats->counter.FUN_00088fb0();
        int nameId = stats->FUN_0008a2d0(); // the argument is evaluated (and stats reloaded) before the lookup call
        const char *name = ((const char *)((owners::Obj_8a060 *)stats)->FUN_0008a060((hulk_intptr)nameId));
        if (state >= 1 && state <= 7 && (other == 0 || memcmp_inline("complete", name, 9) == 0))
            button->complete = 1;
        else
            button->complete = 0;
    }
}
