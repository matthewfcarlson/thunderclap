// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001ebe10 @ 0x001ebe10
struct StringList {
    char data[0x48];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
    void FUN_001ef390(unsigned __int64 id);
};

struct EventSink {
    void *handler;
    bool FUN_001efe20(StringList *args, const void *where, int name, float delay);
};

struct EventConfig {
    EventSink *sink;
    char pad04[4];
    char enabled;
};

struct Registry {
    unsigned __int64 FUN_00079530(int key);
};

struct Source {
    char pad00[0x5c];
    int key;
};

struct Owner {
    char pad00[0x4c];
    Registry *registry;
};

class Emitter {
public:
    Owner *owner;
    void Emit(Source *source, const void *where, int name);
};

extern EventConfig *DAT_004e36d8;

void Emitter::Emit(Source *source, const void *where, int name)
{
    if (source == 0)
        return;
    StringList path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("Props");
    path.FUN_001ef390(owner->registry->FUN_00079530(source->key));
    if (DAT_004e36d8->enabled)
        DAT_004e36d8->sink->FUN_001efe20(&path, where, name, 100.0f);
    path.FUN_001ef350();
}
