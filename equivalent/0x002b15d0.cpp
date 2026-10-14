// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 8/8)
// FUN_002b15d0 @ 0x002b15d0
// pure3d::VertexOffsetExpressionMixer::VertexOffsetExpressionMixer @ 0x002b15d0
struct Source {
    virtual void AddRef();
    virtual void Release();
    char pad04[0xc];
    int *first;
    int *last;
};

struct FUN_0027b070 {
    FUN_0027b070() throw();
    virtual void v0();
    char pad04[0xc];
};

struct IntVector {
    int *first;
    int *last;
    void FUN_002b1010(unsigned int count, int *value);
};

namespace pure3d {
class VertexOffsetExpressionMixer : public FUN_0027b070 {
public:
    Source *source;
    IntVector weights;
    char pad1c[4];
    int f20;
    int f24;
    char pad28[4];
    int f2c;
    int f30;
    VertexOffsetExpressionMixer(Source *s);
    void FUN_002b1490();
    virtual void v1();
};
}

pure3d::VertexOffsetExpressionMixer::VertexOffsetExpressionMixer(Source *s)
{
    source = 0;
    weights.first = 0;
    weights.last = 0;
    f20 = 0;
    f24 = 0;
    f2c = 0;
    f30 = 0;
    if (s)
        s->AddRef();
    if (source)
        source->Release();
    source = s;
    int zero = 0;
    weights.FUN_002b1010(s->last - s->first, &zero);
    for (int i = 0; i < weights.last - weights.first; i++)
        weights.first[i] = 0;
    FUN_002b1490();
}
