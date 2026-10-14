class A_2a46d0 {
  public:
    virtual void F();
    virtual void G();
};
void __stdcall FUN_002a46d0(A_2a46d0** param_1, A_2a46d0* param_2) {
    if (param_2)
        param_2->F();
    if (*param_1)
        (*param_1)->G();
    *param_1 = param_2;
}