extern float kZeroF;
struct A { char pad[8]; A(const float& f); void done(); };
struct Obj { void use(A* a); };
struct T { void* first(); };
struct Base { char pad[0x1b50]; };
struct U { Base* second(); };
class CAIHintAction {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 char pad[0x18];
 void* mThing;
};
void CAIHintAction::vfunc_4() {
 T* a = (T*)mThing;
 U* b = (U*)a->first();
 Base* o = b->second();
 A local(kZeroF);
 ((Obj*)((char*)o + 0x1b50))->use(&local);
 local.done();
}
