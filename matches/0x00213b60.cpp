typedef unsigned int u32;
struct Obj { char pad[8]; char *p; };
extern int FUN_0021ad80(Obj *, u32, u32, u32, u32);
int FUN_00213b60(Obj *self, u32 a, u32 b) {
 char *base = self->p - 8;
 if (*(int *)base == 6) {
  char *item = *(char **)(base + 4);
  if (item[6] == 0) return FUN_0021ad80(self, *(u32 *)(item + 12), a, b, 0);
 }
 return 0;
}
