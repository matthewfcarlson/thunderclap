class Obj { public: char pad[0x150]; int limit; int count; char pad2[0x14]; int *items; };
bool __fastcall target(Obj *p) {
 int i = p->count;
 if (i > 0) {
  if (i < p->limit) {
   do { p->items[i] = -1; ++i; } while (i < p->limit);
  }
  --p->count;
  return true;
 }
 if (i == 0) {
  i = 0;
  if (p->limit > 0) do { p->items[i] = -1; ++i; } while (i < p->limit);
  return true;
 }
 return false;
}