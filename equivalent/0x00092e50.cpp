// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00092e50 @ 0x00092e50
struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

class CUnlockable {
public:
    virtual void v0();
};
class CUnlockableBlonskyFile : public CUnlockable {
public:
    char pad04[0xc];
    Name title;
    char pad18[8];
    Name subtitle;
    char text[0x40];
    char pad68[1];
};

class UnlockableList {
public:
    CUnlockable *items[1];
    void FUN_00092c80(const char *s, int idx);
    void FUN_00092e50(const char *id, int idx, const char *title, const char *subtitle,
                      const char *file, const char *text);
};

void UnlockableList::FUN_00092e50(const char *id, int idx, const char *title, const char *subtitle,
                                  const char *file, const char *text)
{
    if (idx < 0x34 || idx > 0x51)
        return;
    CUnlockableBlonskyFile *g = dynamic_cast<CUnlockableBlonskyFile *>(items[idx]);
    if (g == 0)
        return;
    g->title.FUN_0027b040(title);
    g->subtitle.FUN_0027b040(subtitle);
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
