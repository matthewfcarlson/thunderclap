// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000d7c80 @ 0x000d7c80
class Target;
typedef void (Target::*Fn1_d7c80)(int);
typedef void (Target::*Fn2_d7c80)(int, int);

class Closure_d7c80 {
public:
    Target *object;
    Fn1_d7c80 fn1;
    Fn2_d7c80 fn2;
    int arg1;
    int arg2;
    void Invoke();
};

void Closure_d7c80::Invoke()
{
    if (fn1) {
        (object->*fn1)(arg1);
    } else if (fn2) {
        (object->*fn2)(arg1, arg2);
    }
}
