class BranchNode { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual int vfunc_4(); };
struct Helper { int f(BranchNode*); };
extern "C" void* __cdecl thunk_FUN_0008d690(int);
int BranchNode::vfunc_4() { Helper* p = (Helper*)thunk_FUN_0008d690(0x28); if (p) return p->f(this); return 0; }