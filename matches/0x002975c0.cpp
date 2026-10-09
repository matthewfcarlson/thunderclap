class VisibilityNode { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual int vfunc_4(); };
class Other { public: int helper(VisibilityNode*); };
extern void* alloc(int);
int VisibilityNode::vfunc_4() { void* p = alloc(0x30); if (p) return ((Other*)p)->helper(this); return 0; }