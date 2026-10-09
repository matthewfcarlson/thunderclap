extern "C" void __cdecl CallA(int);
extern "C" int __cdecl CallB();
extern "C" int __cdecl CallC();

class Target {
  public:
    char pad[0x10];
    int state;
    void Run(int value);
};

void Target::Run(int value) {
    CallA(value);
    if (CallB() == 0) {
        if (CallC() == 0) {
            state = 4;
        }
    }
}