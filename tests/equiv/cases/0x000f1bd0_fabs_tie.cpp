struct Vec3 { float x, y, z; };

// Two incoming argument words that the function reuses as an output vector.
struct ArgPair {
    union { int i; float f; unsigned int u; } x;
    union { int i; float f; } y;
};

struct Layout {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void GetExtent(ArgPair *out, void *owner);   // slot 15
};

void __cdecl FUN_000f69e0(int source, Vec3 *out);

class Widget {
public:
    char pad00[0x14];
    Layout *layout;          // 0x14
    char pad18[0x38];
    int source;              // 0x50
    float scaleX;            // 0x54
    float scaleY;            // 0x58
    char pad5c[0xc0];
    int argA;                // 0x11c
    int argB;                // 0x120
    float argC;              // 0x124
    void FUN_000f1bd0(ArgPair args, float c);
};

void Widget::FUN_000f1bd0(ArgPair args, float c) {
    argA = args.x.i;
    argB = args.y.i;
    argC = c;
    union { float f; unsigned int u; } bits;
    bits.f = c;
    args.x.u = bits.u & 0x7fffffff;
    if (args.x.f == 1.5707963705062866f) {
        Vec3 size;
        FUN_000f69e0(source, &size);
        layout->GetExtent(&args, this);
        scaleX = args.x.f / size.y * 0.9f;
        scaleY = args.y.f / size.x * 0.9f;
    }
}
