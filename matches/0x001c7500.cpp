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
    vp = 0x421a3c;
    thunk(t);
}
