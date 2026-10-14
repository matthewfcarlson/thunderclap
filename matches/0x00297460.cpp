extern "C" char DAT_0042d3bc[];
typedef unsigned int u32_297460;
struct Base_297460 {
    void Init(u32_297460);
};
struct Part_297460 {
    void Init();
    char pad[0x40];
};
struct TransformNode {
    char pad[0x28];
    Part_297460 a;
    Part_297460 b;
    u32_297460 field;
    TransformNode* Init(u32_297460);
};
TransformNode* TransformNode::Init(u32_297460 arg) {
    ((Base_297460*)this)->Init(arg);
    *(u32_297460*)this = ((int)DAT_0042d3bc);
    field = 0;
    a.Init();
    b.Init();
    return this;
}
