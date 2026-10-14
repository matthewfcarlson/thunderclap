class Ref_232180 {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner_232180 {
  public:
    char pad[0x14];
    Ref_232180* second;
    Ref_232180* first;
    void Clear();
};
void Owner_232180::Clear() {
    if (first) {
        first->Release();
        first = 0;
    }
    if (second) {
        second->Release();
        second = 0;
    }
}