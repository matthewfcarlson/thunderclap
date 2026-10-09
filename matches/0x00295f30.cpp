class Base { public: Base(); char pad[16]; };
class LeafNode : public Base { public: int x; int y; LeafNode(); };
LeafNode::LeafNode() : Base() { x=6; y=0; *(int*)this = 0x42d23c; }
