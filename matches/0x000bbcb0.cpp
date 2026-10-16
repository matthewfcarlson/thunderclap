class Inner {
  public:
    char pad[0x3c];
    Inner* ptr;
    void Fn(int);
    void Dispatch(int x) {
        if (ptr)
            ptr->Fn(x);
    }
};
class Wrapper {
  public:
    char pad[4];
    Inner* obj;
    void Run(int x);
};
void Wrapper::Run(int x) {
    obj->Dispatch(x);
}