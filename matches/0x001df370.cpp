class Obj {
  public:
    char pad[0x70];
    char flag;
};
class Mid {
  public:
    char pad[0x74];
    Obj* obj;
    Mid* Get();
};
extern "C" Mid* __stdcall Find(int);
char __stdcall Target(int id) {
    Mid* p = Find(id);
    if (!p)
        return 0;
    p = p->Get();
    if (!p)
        return 0;
    Obj* q = p->obj;
    if (!q)
        return 0;
    return q->flag;
}