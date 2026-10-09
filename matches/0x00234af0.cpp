extern int vtBase;
extern int vtList;
class Part {
  public:
    void Init(int);
};
class ParamValueStringList {
  public:
    int vptr;
    int pad;
    Part part;
    ParamValueStringList(int);
};
ParamValueStringList::ParamValueStringList(int x) {
    int* p = &vptr;
    *p = (int)&vtBase;
    part.Init(x);
    *p = (int)&vtList;
}
