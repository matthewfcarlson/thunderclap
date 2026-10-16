class Obj {
  public:
    void Target(int);
    void Other(int);
};
void Obj::Target(int x) {
    Other(1);
}