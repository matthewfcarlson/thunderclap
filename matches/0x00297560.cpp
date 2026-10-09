extern void* VisibilityNode_vftable;
class VisibilityNode {
  public:
    char pad[0x28];
    unsigned char enabled;
    int value;
    VisibilityNode* FUN_002972e0(int);
    VisibilityNode* Init(int);
};
VisibilityNode* VisibilityNode::Init(int x) {
    FUN_002972e0(x);
    *(void**)this = &VisibilityNode_vftable;
    enabled = 1;
    value = 0;
    return this;
}