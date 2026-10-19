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
struct ThisWrap_001df370 {
    Mid* Find(int);
    char Target(int id);
};
char ThisWrap_001df370::Target(int id) {
    Mid* p = this->Find(id);
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