// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001e43b0 @ 0x001e43b0
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
// Finds a prop in the inventory by key, spawns the matching entity and notifies the event sink.
inline void *operator new(unsigned int, void *p) throw() { return p; }

class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Key {
    unsigned int lo, hi;
    Key(const Key &src) throw();
};

struct Event {
    char data[0x28];
    Event *FUN_001ca9a0(Key a, Key b) throw();
};

struct Sink {
    void FUN_001cbc20(Event *e) throw();
};

struct Manager {
    char pad[0x30];
    Sink *sink;                     // 0x30
};

struct Spawner {
    int FUN_001c5080(unsigned int a, int b);
};

struct KeyHolder {
    char pad[8];
    Key key;                        // 8
};

struct Spawned {
    char pad00[8];
    Key key;                        // 8
    char pad10[0xec - 0x10];
    KeyHolder *holder;              // 0xec
    char pad0f0[0x11c - 0xf0];
    Spawner *spawner;               // 0x11c
    char pad120[0x144 - 0x120];
    char flag144;                   // 0x144
    char pad145[0x1d8 - 0x145];
    char flag1d8;                   // 0x1d8
    void FUN_001d7510();
};

class Found {
public:
    virtual void v0();
};

class Inventory {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Found *find(void *caster, unsigned __int64 key);    // slot 3
};

struct Holder2 {
    Inventory *FUN_00203d70();
};

struct Holder1 {
    Holder2 *FUN_000862a0();
};

struct World {
    char pad[0x54];
    Holder1 *f54;                   // 0x54
};

extern World *DAT_004dd700;
extern unsigned int DAT_00421898;

// The key pointer's argument slot is reused for the caster object.
union KeyArg {
    const unsigned __int64 *key;
    int caster;
};

struct Spawn {
    char pad[0x1e830];
    Manager *manager;               // 0x1e830
    Spawned *FUN_001e4310(Found *found, int a, int zero1, int b, int zero2, int c, int zero3);
    void FUN_001e43b0(int a, KeyArg key, int b, int c);
};

void Spawn::FUN_001e43b0(int a, KeyArg key, int b, int c)
{
    Inventory *inv = DAT_004dd700->f54->FUN_000862a0()->FUN_00203d70();
    unsigned __int64 id = *key.key;
    new (&key.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>();
    Found *found = inv->find(&key.caster, id);
    if (!found)
        return;
    Spawned *s = FUN_001e4310(found, a, 0, b, 0, c, 0);
    if (!s)
        return;
    Sink *sink = manager->sink;
    if (sink) {
        Event ev;
        ev.FUN_001ca9a0(s->key, s->holder->key);
        sink->FUN_001cbc20(&ev);
    }
    s->flag144 = 1;
    s->flag1d8 = 1;
    s->spawner->FUN_001c5080(DAT_00421898, 0);
    s->FUN_001d7510();
}
