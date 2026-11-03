// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_0022efb0 @ 0x0022efb0
// FUN_0022efb0 @ 0x0022efb0: clamps a fractional position into [0, count], then moves the cursor there
#include "gen/owners.h"
struct Cursor_22efb0 {
    void FUN_0022e890(int target, float delta);
};

class Track {
public:
    int first;
    char pad04[4];
    Cursor_22efb0 cursor;
    char pad_cursor[0x100 - sizeof(Cursor_22efb0)];
    char fromEnd;
    char pad109[7];
    unsigned int count;
    int FUN_0022efb0(int target, float position);
};

int Track::FUN_0022efb0(int target, float position)
{
    if (position < 0.0f)
        position = 0.0f;
    unsigned int limit = fromEnd ? count : count - 3;
    if ((double)limit < position)
        position = (float)limit;
    ((owners::Obj_22ef20 *)this)->FUN_0022ef20(0, position);
    cursor.FUN_0022e890(target, position - (float)first);
    return target;
}
