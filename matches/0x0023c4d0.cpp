// Same code shape as 0x00231d40 (propagated; names are from that function)
class Branch { char pad[0x28]; };
extern int node_vftable;
class Helper { public: void f(); };
class Helper2 { public: void f(); };
namespace fight { class Node : public Branch { public: virtual void a(); virtual void b(); virtual Node* vfunc_2(unsigned char flags); }; }
void __cdecl thunk_FUN_00267090(fight::Node*);
fight::Node* fight::Node::vfunc_2(unsigned char flags) {
 *(int*)this = (int)&node_vftable;
 ((Helper*)((char*)this + 0x28))->f();
 ((Helper*)this)->f();
 if (flags & 1) thunk_FUN_00267090(this);
 return this;
}