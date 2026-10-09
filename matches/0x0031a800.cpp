struct Obj { int value; int copy; char pad[0x98]; int state; };
void thunk(int);
void __fastcall FUN_0031a800(Obj* p) {
  int i = p->value;
  p->copy = i;
  if (p->state == 1) p->state = 2;
  p->copy = i;
  if (i) thunk(i);
}