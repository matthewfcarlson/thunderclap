struct SimTime {
    virtual void FUN_002ecf60();
    float current;
    float previous;
    SimTime(float time);
};
SimTime::SimTime(float time) {
    previous = time;
    current = time;
}