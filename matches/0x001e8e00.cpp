class Manager_1e8e00 {
  public:
    bool Ready();
    void Finish();
};
extern Manager_1e8e00* gObject_1e8e00;

class State_1e8e00 {
  public:
    int value;
    void update();
};

void State_1e8e00::update() {
    int n = value;
    --n;
    if (n == 0) {
        if (gObject_1e8e00->Ready()) {
            value = 3;
            gObject_1e8e00->Finish();
            gObject_1e8e00 = 0;
        }
    }
}