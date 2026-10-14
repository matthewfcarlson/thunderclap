// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 10/10)
// pure3d::ShadowTraversal::vfunc_4 @ 0x002a1400
struct RenderState_2a1400 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
 virtual void set(float); virtual float get();
 virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void commit();
};
struct Context { char pad[24]; RenderState_2a1400* state; };
struct Engine_2a1400 { char pad[8]; Context* context; };
extern Engine_2a1400* DAT_0052c2b4;
struct Renderer_2a1400 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
 virtual void select(unsigned, unsigned); virtual void begin(unsigned); virtual void end(unsigned);
};
struct RenderRoot { Renderer_2a1400* renderer; };
extern RenderRoot* DAT_0052c2ac;
struct Drawable { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void draw(); };
struct DrawHandle { Drawable* drawable; };
struct Entry_2a1400 { unsigned unused; unsigned key; DrawHandle* handle; unsigned rest[2]; };
struct Scope_2a1400 { void FUN_002a31d0(); void FUN_002a31a0(unsigned); void FUN_002a3250(); char data[12]; };
namespace pure3d {
struct ShadowTraversal {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 char pad04[16]; unsigned enabled; char pad18[8]; Scope_2a1400 scope; unsigned active; unsigned mode; unsigned unused34; unsigned count; Entry_2a1400* entries;
};
void ShadowTraversal::vfunc_4() {
 if (!count || !active || !enabled) return;
 float old = DAT_0052c2b4->context->state->get();
 DAT_0052c2b4->context->state->set(old * 0.995f);
 DAT_0052c2b4->context->state->commit();
 DAT_0052c2ac->renderer->begin(0);
 scope.FUN_002a31d0();
 scope.FUN_002a31a0(mode);
 for (unsigned i=0; i<count; ++i) {
 DAT_0052c2ac->renderer->select(0, entries[i].key);
 entries[i].handle->drawable->draw();
 }
 scope.FUN_002a3250();
 DAT_0052c2ac->renderer->end(0);
 DAT_0052c2b4->context->state->set(old);
 DAT_0052c2b4->context->state->commit();
}
}