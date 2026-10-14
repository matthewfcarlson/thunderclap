class X_15aa60 {
  public:
    char pad[0x78];
    int* Get();
};
int* X_15aa60::Get() {
    return (int*)((char*)this + 0x78);
}