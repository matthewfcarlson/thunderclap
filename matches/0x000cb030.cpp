class Obj {
  public:
    char pad[0x88];
    Obj* ptr;
    void Run(int);
    void Forward(int);
};
void Obj::Forward(int x) {
    if (ptr)
        ptr->Run(x);
}