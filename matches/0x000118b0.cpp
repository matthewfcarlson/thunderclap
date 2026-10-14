class C {
  public:
    int lo;
    int hi;
    __int64 Get();
};
__int64 C::Get() {
    return *(__int64*)this;
}
