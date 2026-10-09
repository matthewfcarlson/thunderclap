namespace pure3d {
class pddiRenderState {
  public:
    pddiRenderState() {}
    virtual void f();
    char p[0x18];
};
template <class T> class pddiStack {
  public:
    virtual void g();
    int n;
    int top;
    T* arr;
    pddiStack(int cnt);
};
void* FUN_0008d690(int sz);
template <class T> pddiStack<T>::pddiStack(int cnt) {
    T* a = (T*)FUN_0008d690(cnt * 0x1c);
    T* b;
    if (a) {
        T* q = a;
        for (int i = cnt - 1; i >= 0; i--) {
            q->pddiRenderState::pddiRenderState();
            q++;
        }
        b = a;
    } else
        b = 0;
    n = cnt;
    arr = b;
    top = 0;
}
template pddiStack<pddiRenderState>::pddiStack(int);
} // namespace pure3d
