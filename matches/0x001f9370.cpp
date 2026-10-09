typedef unsigned short ushort;
struct C {
    void f(int param_2, char param_3);
};
void C::f(int param_2, char param_3) {
    if (param_3)
        *reinterpret_cast<ushort*>(this) |= (ushort)(1 << param_2);
    else
        *reinterpret_cast<ushort*>(this) &= (ushort) ~(1 << param_2);
}