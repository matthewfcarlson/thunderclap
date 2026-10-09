extern int FindThing(int, int);
extern void DoThing(int, int, void*);

class Owner {
public:
    char pad[4];
    int value;
    void Run(int a, int b);
};

void Owner::Run(int param2, int param3) {
    int found = FindThing(value, param2);
    if (found != 0) {
        int local[2];
        local[1] = param3;
        local[0] = 0;
        DoThing(value, found, local);
    }
}