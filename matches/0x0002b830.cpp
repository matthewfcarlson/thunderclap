class Obj {
  public:
    void Act(int, int);
    char Run(const char*);
};
struct This_Lookup {
    int Lookup(const char*);
};
char Obj::Run(const char* s) {
    int i = ((This_Lookup*)this)->Lookup(s);
    if (i == -1)
        return 0;
    Act(i, 0);
    return 1;
}