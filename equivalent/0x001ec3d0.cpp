// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001ec3d0 @ 0x001ec3d0
struct StringList {
    char data[0x44];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
};

struct Level {
    void *FUN_00086310();
};

struct Handler {
    void FUN_001f46a0();
};

struct EventSink {
    Handler *handler;
    bool FUN_001efe20(StringList *args, int zero, const char *name, float delay);
};

class LevelEnter {
public:
    void FUN_001ec3d0();

    EventSink *sink;
    Level *level;
    char active;
    char entered;
};

void FUN_001eb440(void *id, StringList *out);

void LevelEnter::FUN_001ec3d0()
{
    if (!active)
        return;
    void *id = level->FUN_00086310();
    if (!id)
        return;
    StringList path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("World");
    FUN_001eb440(id, &path);
    if (entered) {
        entered = 0;
        sink->handler->FUN_001f46a0();
    } else if (active) {
        sink->FUN_001efe20(&path, 0, "EnterLevel", 100.0f);
    }
    path.FUN_001ef350();
}
