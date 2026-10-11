extern "C" char DAT_0042d3bc[];
typedef unsigned int u32;
struct Base {
    void Init(u32);
};
struct Part {
    void Init();
    char pad[0x40];
};
struct TransformNode {
    char pad[0x28];
    Part a;
    Part b;
    u32 field;
    TransformNode* Init(u32);
};
TransformNode* TransformNode::Init(u32 arg) {
    ((Base*)this)->Init(arg);
    *(u32*)this = ((int)DAT_0042d3bc);
    field = 0;
    a.Init();
    b.Init();
    return this;
}
