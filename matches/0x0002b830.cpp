class Obj {
  public:
    void Act(int, int);
    char Run(const char*);
};
int __stdcall Lookup(const char*);
char Obj::Run(const char* s) {
    int i = Lookup(s);
    if (i == -1)
        return 0;
    Act(i, 0);
    return 1;
}