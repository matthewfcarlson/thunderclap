class Obj {
  public:
    char m[28];
    char v;
    char Fn(char a);
};
char Obj::Fn(char a) {
    v = a;
    return 1;
}
