struct T;
class O_12980 {
  public:
    char pad[0x58];
    T* Get();
};
T* O_12980::Get() {
    return (T*)((char*)this + 0x58);
}
