typedef unsigned char byte_2b1200;
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
class Thing_2b1200 {
  public:
    void* mValue;
    Thing_2b1200* Destroy(byte_2b1200 flags);
};
Thing_2b1200* Thing_2b1200::Destroy(byte_2b1200 flags) {
    if (mValue != 0)
        FUN_0008d340(mValue);
    if ((flags & 1) != 0)
        FUN_0008d330(this);
    return this;
}
