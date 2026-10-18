// FUN_001eb740 @ 0x001eb740
// FUN_001eb740: build a search list ("Objects", "Dialogue", name) and start a lookup
// equiv-map: ??0StrList@@QAE@XZ = 0x001ef320
// equiv-map: ??1StrList@@QAE@XZ = 0x001ef350
// equiv-map: ??0Name@@QAE@PBD@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct StrList {
    char data[0x48];
    StrList() throw();
    ~StrList() throw();
    void FUN_001ef370(const char *s) throw();
};

struct Name {
    char data[8];
    Name(const char *s) throw();
    ~Name() throw();
};

struct Finder_1eb740 {
    int FUN_00086310() throw();
};

struct Sink_1eb740 {
    void FUN_001efe20(StrList *list, Name *name, int a, float scale) throw();
};

void __cdecl FUN_001eb440(int found, StrList *list) throw();

class Loader_1eb740 {
public:
    Sink_1eb740 *sink;
    Finder_1eb740 *finder;
    char enabled;

    void FUN_001eb740(const char *dir, int a, const char *name) throw();
};

void Loader_1eb740::FUN_001eb740(const char *dir, int a, const char *name)
{
    StrList list;
    list.FUN_001ef370("Objects");
    list.FUN_001ef370("Dialogue");
    list.FUN_001ef370(dir);
    int found = finder->FUN_00086310();
    if (found != 0)
        FUN_001eb440(found, &list);
    Name n(name);
    if (enabled)
        sink->FUN_001efe20(&list, &n, a, 100.0f);
}
