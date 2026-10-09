struct Obj { void* f(); };
struct Obj2 { void* g(); };
struct Obj3 { void h(void*); };
class CAction { public: char pad[0x1c]; Obj* one; Obj* two; };
class CAIHintAction : public CAction { public: bool vfunc_6(int); };
bool CAIHintAction::vfunc_6(int x) {
 Obj* o = one;
 void* a = o->f();
 void* b = ((Obj2*)a)->g();
 ((Obj3*)((char*)b + 0x1b50))->h((char*)two + 0x18);
 return true;
}