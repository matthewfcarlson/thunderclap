// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_00249630 @ 0x00249630
struct Node { Node* next; int value; };
float __cdecl FUN_00241700(int, int);
float __cdecl FUN_00241710(int, int);
struct Object { char pad0[8]; float scale; float base; float outputScale; float outputBase; char pad18[24]; int state; float amount; int duration; Node* nodes; int unknown40; int key; };
// equiv-conv: target edi stack
void __cdecl target(Object* self, int delta) {
 if(self->state == 1 || self->state == 3) {
  double step = (double)delta / self->duration;
  if (step >= 0.1f) step = 0.1f;
  if(self->state == 1) {
   double a = (double)self->amount - step;
   self->amount = (float)a;
   if(a <= 0.0f) { self->amount=0.0f; self->state=0; }
  } else {
   double a = (double)self->amount + step;
   self->amount=(float)a;
   if(a >= 1.0f) { self->amount=1.0f; self->state=2; }
  }
 }
 float scale = self->amount * self->scale;
 float base = self->base;
 int key = self->key;
 for(Node* n=self->nodes; n; n=n->next) {
  scale = FUN_00241700(key,n->value) * scale;
  base = FUN_00241710(key,n->value) * base;
 }
 self->outputScale=scale;
 self->outputBase=base;
}