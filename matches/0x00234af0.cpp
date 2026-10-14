extern int vtBase_234af0;
extern int vtList;
class Part_234af0 {
  public:
    void Init(int);
};
class ParamValueStringList {
  public:
    int vptr;
    int pad;
    Part_234af0 part;
    ParamValueStringList(int);
};
ParamValueStringList::ParamValueStringList(int x) {
    int* p = &vptr;
    *p = (int)&vtBase_234af0;
    part.Init(x);
    *p = (int)&vtList;
}
