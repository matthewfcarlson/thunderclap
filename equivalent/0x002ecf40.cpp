// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002ecf40 @ 0x002ecf40
struct SimTime {
    virtual void FUN_002ecf60();
    unsigned int current;
    unsigned int previous;
    SimTime(unsigned int time);
};

SimTime::SimTime(unsigned int time) {
    current = time;
    previous = time;
}
