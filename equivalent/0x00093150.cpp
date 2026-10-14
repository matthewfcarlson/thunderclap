// STATUS: equivalent (tools/equiv.py level 3: 1169 inputs, branch coverage 12/12)
// FUN_00093150 @ 0x00093150
struct Name_93150 {
    char data[8];
    void FUN_0027b040(const char *s);
};

class CUnlockable {
public:
    virtual void v0();
};
class CUnlockableGallery : public CUnlockable {
public:
    char pad04[0xc];
    Name_93150 title;
    char pad18[8];
    int flags;
    char caption[0x40];
    char path[0x40];
    char pada4[4];
    Name_93150 subtitle;
};

class UnlockableList_93150 {
public:
    CUnlockable *items[1];
    void FUN_00092c80(const char *s, int idx);
    void FUN_00093150(const char *id, int idx, const char *title, const char *subtitle,
                      const char *caption, const char *path, int flags);
};

void UnlockableList_93150::FUN_00093150(const char *id, int idx, const char *title, const char *subtitle,
                                  const char *caption, const char *path, int flags)
{
    CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(items[idx]);
    if (g == 0)
        return;
    g->title.FUN_0027b040(title);
    g->subtitle.FUN_0027b040(subtitle);
    if (caption) {
        const char *s = caption;
        char *d = g->caption;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    if (path) {
        const char *s = path;
        char *d = g->path;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    g->flags = flags;
    if (*id)
        FUN_00092c80(id, idx);
}
