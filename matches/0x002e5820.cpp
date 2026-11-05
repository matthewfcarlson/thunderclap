// Same code shape as 0x002b1200 (propagated; names are from that function)
typedef unsigned char byte_2e5820;
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
class Thing_2e5820 {
  public:
    void* mValue;
    Thing_2e5820* Destroy(byte_2e5820 flags);
};
Thing_2e5820* Thing_2e5820::Destroy(byte_2e5820 flags) {
    if (mValue != 0)
        FUN_0008d340(mValue);
    if ((flags & 1) != 0)
        FUN_0008d330(this);
    return this;
}
