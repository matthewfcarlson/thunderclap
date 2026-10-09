class Manager { public: bool Ready(); void Finish(); };
extern Manager* gObject;

class State {
public:
    int value;
    void update();
};

void State::update() {
    int n = value;
    --n;
    if (n == 0) {
        if (gObject->Ready()) {
            value = 3;
            gObject->Finish();
            gObject = 0;
        }
    }
}