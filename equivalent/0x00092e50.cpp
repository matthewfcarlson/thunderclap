// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00092e50 @ 0x00092e50
#include "gen/owners.h"
struct Name_92e50 {
    char data[8];
};

class CUnlockable_92e50 {
public:
    virtual void v0();
};
class CUnlockableBlonskyFile_92e50 : public CUnlockable_92e50 {
public:
    char pad04[0xc];
    Name_92e50 title;
    char pad18[8];
    Name_92e50 subtitle;
    char text[0x40];
    char pad68[1];
};

class UnlockableList_92e50 {
public:
    CUnlockable_92e50 *items[1];
    void FUN_00092c80(const char *s, int idx);
    void FUN_00092e50(const char *id, int idx, const char *title, const char *subtitle,
                      const char *file, const char *text);
};

void UnlockableList_92e50::FUN_00092e50(const char *id, int idx, const char *title, const char *subtitle,
                                  const char *file, const char *text)
{
    if (idx < 0x34 || idx > 0x51)
        return;
    CUnlockableBlonskyFile_92e50 *g = dynamic_cast<CUnlockableBlonskyFile_92e50 *>(items[idx]);
    if (g == 0)
        return;
    ((owners::Target_27b040 *)&(g->title))->FUN_0027b040((hulk_uintptr)title);
    ((owners::Target_27b040 *)&(g->subtitle))->FUN_0027b040((hulk_uintptr)subtitle);
    {
        const char *s = file;
        char *d = (char *)g + 0x68;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    if (text) {
        const char *s = text;
        char *d = g->text;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    if (*id)
        FUN_00092c80(id, idx);
}
