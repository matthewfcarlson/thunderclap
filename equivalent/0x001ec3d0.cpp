// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001ec3d0 @ 0x001ec3d0
struct StringList_1ec3d0 {
    char data[0x44];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
};

struct Level_1ec3d0 {
    void *FUN_00086310();
};

struct Handler_1ec3d0 {
    void FUN_001f46a0();
};

struct EventSink_1ec3d0 {
    Handler_1ec3d0 *handler;
    bool FUN_001efe20(StringList_1ec3d0 *args, int zero, const char *name, float delay);
};

class LevelEnter {
public:
    void FUN_001ec3d0();

    EventSink_1ec3d0 *sink;
    Level_1ec3d0 *level;
    char active;
    char entered;
};

void FUN_001eb440(void *id, StringList_1ec3d0 *out);

void LevelEnter::FUN_001ec3d0()
{
    if (!active)
        return;
    void *id = level->FUN_00086310();
    if (!id)
        return;
    StringList_1ec3d0 path;
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
