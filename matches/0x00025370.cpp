struct Ctx { int pad[17]; int Find(int); };
struct Act { int pad; void Do(int); };
struct Target {
  int *vt;
  int pad[2];
  int count;
  int items[1];
  void Run(int arg);
};
void Target::Run(int arg) {
  int i = 0;
  while (i < count) {
    Ctx *c = (Ctx*)vt[17];
    int r = c->Find(items[i]);
    if (r) ((Act*)r)->Do(arg);
    ++i;
  }
}
