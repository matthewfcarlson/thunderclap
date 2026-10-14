// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 16/16)
// pure3d::VertexAnimPrimGroup::vfunc_6 @ 0x002e0a60
struct Ref {
 virtual void vfunc_0();
 virtual void vfunc_1();
};
struct State { char pad[0x58]; Ref* current; };
struct Renderer {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual Ref* vfunc_7();
 virtual void vfunc_8(Ref*);
 char pad[0x58];
 State* state;
};
namespace pure3d {
struct VertexAnimPrimGroup {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 char pad0[0x3c];
 Ref* material;
 char pad1[0x14];
 Renderer* renderer;
 Ref* animation;
};
void VertexAnimPrimGroup::vfunc_6() {
 Renderer* r = renderer;
 State* state = r->state;
 Ref* previous = state->current;
 Ref* saved = r->vfunc_7();
 if (previous) previous->vfunc_0();
 Ref* replacement = animation;
 if (replacement) replacement->vfunc_0();
 if (state->current) state->current->vfunc_1();
 state->current = replacement;
 if (saved) saved->vfunc_0();
 renderer->vfunc_8(material);
 renderer->vfunc_6();
 renderer->vfunc_8(saved);
 if (saved) saved->vfunc_1();
 if (previous) previous->vfunc_0();
 if (state->current) state->current->vfunc_1();
 state->current = previous;
 if (previous) previous->vfunc_1();
}
}
