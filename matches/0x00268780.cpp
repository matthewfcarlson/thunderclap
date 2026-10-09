class ControllerXBox {
  public:
    char pad[8];
    int handle;
    void vfunc_21(int);
};
extern void __stdcall XInputClose(int);
void ControllerXBox::vfunc_21(int p) {
    if (handle)
        XInputClose(handle);
    handle = p;
}