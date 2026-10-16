class Obj {
  public:
    char Act(int);
};
Obj* __stdcall Find(int);
char __stdcall Target(int id, int arg) {
    char result = 0;
    Obj* p = Find(id);
    if (p)
        result = p->Act(arg);
    return result;
}