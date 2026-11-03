class A_2a46d0 {
  public:
    virtual void F();
    virtual void G();
};
void __stdcall FUN_002a46d0(A_2a46d0** slot, A_2a46d0* object) {
    if (object)
        object->F();
    if (*slot)
        (*slot)->G();
    *slot = object;
}