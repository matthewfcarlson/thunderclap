// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00297500 @ 0x00297500
struct VisibilityNode;
struct Resource {
    virtual void addRef();
    virtual void release();
    virtual void reserved2();
    virtual void reserved3();
    virtual Resource* clone();
    void FUN_002a7cf0(VisibilityNode* node);
};
struct BranchNode_297500 {};
struct VisibilityNode : BranchNode_297500 {
    virtual void reserved0();
    char pad[0x24];
    unsigned char visible;
    char pad2[3];
    Resource* resource;
    VisibilityNode* FUN_002971f0(VisibilityNode* other);
    VisibilityNode(VisibilityNode* other);
};
VisibilityNode::VisibilityNode(VisibilityNode* other)
    : BranchNode_297500((FUN_002971f0(other), BranchNode_297500())) {
    visible = other->visible;
    resource = 0;
    if (other->resource) {
        Resource* copy = other->resource->clone();
        if (copy) copy->addRef();
        if (resource) resource->release();
        resource = copy;
        if (copy) copy->FUN_002a7cf0(this);
    }
}