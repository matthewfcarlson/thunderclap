// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 19/24, incomplete)
// FUN_002e6340 @ 0x002e6340
#include "compat/ptr.h"
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);
void* FUN_0008d6d0(hulk_uintptr size);
extern "C" void* memset(void* dst, int c, unsigned int n);

struct Stream {
    void FUN_002647e0(void* dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad00[0x284];
    Stream* stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

class RefCounted_2e6340 {
public:
    virtual void AddRef();
    virtual void Release();
    int pad04;
    int id;
};

struct Track {
    RefCounted_2e6340** begin;
    RefCounted_2e6340** end;
    int cap;
};

struct KeyVec {
    unsigned int* begin;
    unsigned int* end;
    int cap;
    void FUN_002e16f0(unsigned int n, const unsigned int* fill);
};

struct TrackVec {
    Track* begin;
    Track* end;
    int cap;
    void FUN_002e6160(unsigned int n, const __int64* fill);
};

struct Parent;

namespace pure3d {

class VertexAnimKeyFrameList {
public:
    virtual void v0();
    int field04;
    KeyVec keys;
    TrackVec tracks;

    VertexAnimKeyFrameList()
    {
        field04 = 0;
        keys.begin = 0;
        keys.end = 0;
        tracks.begin = 0;
        tracks.end = 0;
    }

    void FUN_002e5330(int key, unsigned int* index);
};

}

class KeyFrameLoader {
public:
    RefCounted_2e6340* FUN_002e5b20(Reader* r, Parent* parent);
    pure3d::VertexAnimKeyFrameList* FUN_002e6340(Reader* r, Parent* parent);
};

pure3d::VertexAnimKeyFrameList* KeyFrameLoader::FUN_002e6340(Reader* r, Parent* parent)
{
    struct Frame {
        unsigned int scratch;
        unsigned int count;
        unsigned int offset;
        pure3d::VertexAnimKeyFrameList* list;
        KeyFrameLoader* self;
        __int64 zeroFill;
        unsigned int spare;
        unsigned int counts[512];
    } f;

    f.self = this;
    r->stream->FUN_002647e0(&f.scratch, 1, 4, 1);

    f.list = 0;
    void* mem = FUN_0008d690(0x20);
    if (mem)
        f.list = new (mem) pure3d::VertexAnimKeyFrameList();

    r->stream->FUN_002647e0(&f.count, 1, 4, 1);

    unsigned int n = f.count;
    f.scratch = 0;
    f.list->keys.FUN_002e16f0(n, &f.scratch);
    f.zeroFill = 0;
    f.list->tracks.FUN_002e6160(n, &f.zeroFill);
    r->stream->FUN_002647e0(f.list->keys.begin, n, 4, 1);

    f.offset = 0;
    for (f.scratch = n; f.scratch != 0; f.scratch--, f.offset += sizeof(Track)) {
        r->stream->FUN_002647e0(&f.count, 1, 4, 1);
        Track* track = (Track*)((char*)f.list->tracks.begin + f.offset);
        if (track->begin == 0) {
            if (f.count == 0) {
                track->begin = 0;
                track->end = 0;
            } else {
                unsigned int bytes = f.count * 4;
                RefCounted_2e6340** p = (RefCounted_2e6340**)FUN_0008d6d0(bytes);
                track->begin = p;
                if (p == 0) {
                    track->begin = 0;
                    track->end = 0;
                } else {
                    track->end = (RefCounted_2e6340**)((char*)p + bytes);
                    for (unsigned int k = f.count; k != 0; k--, p++)
                        new (p) RefCounted_2e6340*(0);
                }
            }
        }
    }

    memset(f.counts, 0, sizeof(f.counts));
    f.scratch = 0;
    while (r->FUN_002669f0()) {
        if (r->FUN_00266a30() == 0x121306) {
            RefCounted_2e6340* obj = f.self->FUN_002e5b20(r, parent);
            f.list->FUN_002e5330(obj->id, &f.scratch);
            unsigned int* used = &f.counts[f.scratch];
            RefCounted_2e6340** slot = &f.list->tracks.begin[f.scratch].begin[*used];
            obj->AddRef();
            if (*slot)
                (*slot)->Release();
            *slot = obj;
            (*used)++;
        }
        r->FUN_00266be0();
    }
    return f.list;
}
