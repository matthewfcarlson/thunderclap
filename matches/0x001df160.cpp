class Obj {
  public:
    char Act(int);
};
struct ThisWrap_001df160 {
    Obj* Find(int);
    char Target(int id, int arg);
};
char ThisWrap_001df160::Target(int id, int arg) {
    char result = 0;
    Obj* p = this->Find(id);
    if (p)
        result = p->Act(arg);
    return result;
}