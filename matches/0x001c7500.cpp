extern "C" char DAT_00421a3c[];
void thunk(int);
class StoreBase {
  public:
    int vp;
    int a[4];
    int b;
    void Fn();
};
void StoreBase::Fn() {
    int t = b;
    vp = ((int)DAT_00421a3c);
    thunk(t);
}
