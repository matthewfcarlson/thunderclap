// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 46/46)
// FUN_0025d7f0 @ 0x0025d7f0
namespace audio {
class SeqAction {
public:
    virtual void vfunc_0();
    char *link;
};
class SeqActionStream : public SeqAction {
public:
    virtual void vfunc_1();
    char pad08[0x18 - 0x08];
    int index;
};
}

struct Handle;
extern "C" int __cdecl FUN_0024afe0(Handle *h);
extern "C" Handle *__cdecl FUN_0024b030(Handle *h);
extern "C" int __cdecl FUN_0024c2d0(Handle *h);
struct SortKey { unsigned value; int index; };
struct Block4_25d7f0 { unsigned a, b, c, d; int index; };
extern "C" void __cdecl FUN_0024b060(Handle *h, SortKey *keys, int count);
extern "C" void __cdecl FUN_0024b050(Handle *h, Block4_25d7f0 *blocks, int count);

struct Sink_25d7f0 {
    virtual void vfunc_0();
    virtual void vfunc_1(void *owner, Handle *h);
};
struct Mgr_25d7f0 {
    char pad[0xac];
    Sink_25d7f0 *sink;
};
struct Owner_25d7f0 {
    char pad[0x3c];
    unsigned *keys;
    unsigned *blocks;
};

struct Frame_25d7f0 {
    char pad0[2];
    char count;
    char missing;
    int savedThis;
    SortKey keys[16];
    Block4_25d7f0 blocks[16];
};

struct Self_25d7f0 {
    char pad0[4];
    Owner_25d7f0 *owner;
    char pad08[0x34 - 8];
    Handle *handle;
    char pad38[4];
    Mgr_25d7f0 *mgr;
    char *streams;
    char pad44[0x54 - 0x44];
    char first;
    char pad55[3];
    int mode;
    char flag5c;

    void FUN_0025d7f0();
};

void Self_25d7f0::FUN_0025d7f0()
{
    Frame_25d7f0 fr;
    first = (char)0xff;
    char *head = streams;
    audio::SeqAction *obj = head ? (audio::SeqAction *)(head - 4) : 0;
    fr.count = 0;
    fr.missing = 0;
    bool skipToNotify = true;
    if (dynamic_cast<audio::SeqActionStream *>(obj) != 0 && obj != 0) {
        do {
            audio::SeqActionStream *s = dynamic_cast<audio::SeqActionStream *>(obj);
            if (s != 0) {
                s->index = fr.count;
                if (fr.missing == 0)
                    first = fr.count;
                fr.count++;
            } else {
                fr.missing = 1;
            }
            char *n = obj->link;
            if (n == 0)
                break;
            obj = (audio::SeqAction *)(n - 4);
        } while (obj != 0);
        skipToNotify = (fr.count == 0 || mode == 5);
    }
    bool other = true;
    if (skipToNotify) {
        if (handle != 0) {
            other = false;
            if (FUN_0024afe0(handle) == 0) {
                Mgr_25d7f0 *m = mgr;
                m->sink->vfunc_1(m, handle);
                handle = 0;
            }
        }
    }
    if (other) {
        if (flag5c != 0 && handle != 0) {
            if (FUN_0024afe0(handle) == 0)
                flag5c = 0;
        }
    }
    if (handle == 0)
        return;
    unsigned *src = owner->keys;
    int n = FUN_0024c2d0(FUN_0024b030(handle));
    if (src != 0) {
        for (int i = 0; i < n; i++) {
            fr.keys[i].value = src[i];
            fr.keys[i].index = i;
        }
        FUN_0024b060(handle, fr.keys, n);
    }
    unsigned *blk = owner->blocks;
    if (blk != 0) {
        for (int i = 0; i < n; i++) {
            fr.blocks[i].a = blk[i * 4];
            fr.blocks[i].b = blk[i * 4 + 1];
            fr.blocks[i].c = blk[i * 4 + 2];
            fr.blocks[i].d = blk[i * 4 + 3];
            fr.blocks[i].index = i;
        }
        FUN_0024b050(handle, fr.blocks, n);
    }
}
