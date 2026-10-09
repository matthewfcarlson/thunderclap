struct H { void A(); void B(); };
void thunk_FUN_00267090(H*);
struct T { int value; void run(H*); };
void T::run(H* arg) {
    ((H*)this)->A();
    arg->A();
    if (arg) { arg->B(); thunk_FUN_00267090(arg); }
    *(int*)this = 0;
}