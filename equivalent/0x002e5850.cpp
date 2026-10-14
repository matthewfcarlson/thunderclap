// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e5850 @ 0x002e5850
struct Segment_2e5850 {
    int *begin;
    int *end;
    int cap;
};

class Source_2e5850 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x10];
    Segment_2e5850 *segments;
    char FUN_002e5330(unsigned int key, unsigned int *outIndex);
};

class SegmentCursor {
public:
    unsigned int key;
    unsigned int index;
    int last;
    Source_2e5850 *source;
    SegmentCursor(Source_2e5850 *src, unsigned int k);
};

SegmentCursor::SegmentCursor(Source_2e5850 *src, unsigned int k)
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
        Segment_2e5850 *s = &source->segments[index];
        last = (int)(s->end - s->begin) - 1;
    }
}
