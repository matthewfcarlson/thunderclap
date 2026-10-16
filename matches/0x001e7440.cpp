int __stdcall Lookup(int);
class Obj {
  public:
    char Act(int);
    char Find(int);
};
char Obj::Find(int x) {
    char result = 0;
    int n = Lookup(x);
    if (n >= 0) {
        Act(n);
        result = 1;
    }
    return result;
}