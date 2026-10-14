class X_5a3f0 {
  public:
    int A();
};
class Y_5a3f0 {
  public:
    int B();
};
int __cdecl target(X_5a3f0* param) {
    if (param != 0) {
        int a = param->A();
        if (a != 0) {
            int b = ((Y_5a3f0*)a)->B();
            if (b != 0) {
                int c = *(int*)(b + 0x334);
                if (c != 0)
                    return c + 0xdc;
                int d = *(int*)(b + 0x330);
                if (d != 0)
                    return d + 0xdc;
            }
        }
    }
    return 0;
}