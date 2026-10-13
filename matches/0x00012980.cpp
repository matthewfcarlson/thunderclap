struct T;
class O {
  public:
    char pad[0x58];
    T* Get();
};
T* O::Get() {
    return (T*)((char*)this + 0x58);
}
