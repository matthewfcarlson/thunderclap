struct Elem { void f(int); };
struct Obj { char pad[0x10]; unsigned int limit; char pad2[4]; int count; int *items; void target(int); };
void Obj::target(int arg) {
 int n = count;
 for (int i=0; i<=n; ++i) {
  if ((unsigned)i < limit && items[i] != 0) ((Elem*)items[i])->f(arg);
 }
}