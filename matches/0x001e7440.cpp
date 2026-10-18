struct This_Lookup {
    int Lookup(int);
};
class Obj {
  public:
    char Act(int);
    char Find(int);
};
char Obj::Find(int x) {
    char result = 0;
    int n = ((This_Lookup*)this)->Lookup(x);
    if (n >= 0) {
        Act(n);
        result = 1;
    }
    return result;
}