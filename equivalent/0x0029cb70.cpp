// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 10/10)
// FUN_0029cb70 @ 0x0029cb70
// Age the pool's entries by the time elapsed since `since`: expire the ones whose lifetime is used up
// and queue the finished ones for reuse.
struct Entry_29cb70 {
    char pad0[0x14];
    unsigned int lifetime;
    int payload;
};

class Sub_29cb70 {
public:
    char pad0[0x28];
    void FUN_00231070();
    void FUN_00231590(int payload, int flag, Entry_29cb70* entry);
};

extern unsigned int* DAT_0052c2b4;

class Pool_29cb70 {
public:
    char pad0[4];
    Sub_29cb70 sub;
    Entry_29cb70* entries;
    Entry_29cb70** finished;
    int count;
    int finishedCount;

    void FUN_0029cb70(unsigned int since);
};

void Pool_29cb70::FUN_0029cb70(unsigned int since)
{
    unsigned int now = *DAT_0052c2b4;
    if (now > since) {
        since = now - since;
    } else {
        since = 1;
    }
    sub.FUN_00231070();
    for (int i = 0; i < count; ++i) {
        Entry_29cb70* e = &entries[i];
        if (e->lifetime != 0) {
            if (e->lifetime > since) {
                sub.FUN_00231590(e->payload, 0, e);
            } else {
                finished[finishedCount] = e;
                ++finishedCount;
                entries[i].lifetime = 0;
            }
        }
    }
}
