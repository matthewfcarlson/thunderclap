// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e5850 @ 0x002e5850
struct Segment {
    int *begin;
    int *end;
    int cap;
};

class Source {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x10];
    Segment *segments;
    char FUN_002e5330(unsigned int key, unsigned int *outIndex);
};

class SegmentCursor {
public:
    unsigned int key;
    unsigned int index;
    int last;
    Source *source;
    SegmentCursor(Source *src, unsigned int k);
};

SegmentCursor::SegmentCursor(Source *src, unsigned int k)
{
    key = 0;
    index = 0;
    last = 0;
    source = 0;
    if (src != 0)
        src->AddRef();
    if (source != 0)
        source->Release();
    source = src;
    key = k;
    index = 0;
    last = -1;
    if (source->FUN_002e5330(k, &index) == 1) {
        Segment *s = &source->segments[index];
        last = (int)(s->end - s->begin) - 1;
    }
}
