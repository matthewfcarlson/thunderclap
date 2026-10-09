struct Obj { Obj *a(); Obj *b(); unsigned int c(); unsigned int d(int); };
struct State { char pad[0x10]; int value; };
struct PropDropAction { char pad[0x1c]; State *state; Obj *thing; bool vfunc_3(int,int); };
bool PropDropAction::vfunc_3(int x,int y) {
 if (thing) {
  Obj *p=thing->a(); p=p->b();
  int n=state->value;
  if(n<0) { p->c(); return false; }
  p->d(n);
 }
 return false;
}