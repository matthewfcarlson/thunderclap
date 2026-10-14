// Same code shape as 0x000906f0 (propagated; names are from that function)
struct Entry_90df0 {
    void Act();
};
class C_90df0 {
  public:
    int Find(int);
    void Target(int);
};
void C_90df0::Target(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry_90df0*)((char*)this + i * 64))->Act();
}