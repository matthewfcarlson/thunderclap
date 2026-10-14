struct Entry_906f0 {
    void Act();
};
class C_906f0 {
  public:
    int Find(int);
    void Target(int);
};
void C_906f0::Target(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry_906f0*)((char*)this + i * 64))->Act();
}