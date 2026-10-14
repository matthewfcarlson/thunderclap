// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000d7c80 @ 0x000d7c80
class Target;
typedef void (Target::*Fn1)(int);
typedef void (Target::*Fn2)(int, int);

class Closure {
public:
    Target *object;
    Fn1 fn1;
    Fn2 fn2;
    int arg1;
    int arg2;
    void Invoke();
};

void Closure::Invoke()
{
    if (fn1) {
        (object->*fn1)(arg1);
    } else if (fn2) {
        (object->*fn2)(arg1, arg2);
    }
}
