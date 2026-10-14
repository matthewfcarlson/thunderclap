struct A_171840 {
    A_171840* f592a0();
    A_171840* f59a30();
    void f37120(int);
};
class IntentionClearAction {
  public:
    char pad[0x20];
    A_171840* field;
    void vfunc_4();
};
void IntentionClearAction::vfunc_4() {
    A_171840* x = field->f592a0();
    x = x->f59a30();
    x->f37120(0);
}