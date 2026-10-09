struct Entry {
    void Act();
};
class C {
  public:
    int Find(int);
    void Target(int);
};
void C::Target(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry*)((char*)this + i * 64))->Act();
}