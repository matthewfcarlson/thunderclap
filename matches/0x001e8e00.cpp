#include "decls/data/game/global.h"
// data: gObject_1e8e00 = DAT_004e3694

class Manager_1e8e00 {
  public:
    bool Ready();
    void Finish();
};

class State_1e8e00 {
  public:
    int value;
    void update();
};

void State_1e8e00::update() {
    int n = value;
    --n;
    if (n == 0) {
        if ((*(Manager_1e8e00**)&DAT_004e3694)->Ready()) {
            value = 3;
            (*(Manager_1e8e00**)&DAT_004e3694)->Finish();
            (*(Manager_1e8e00**)&DAT_004e3694) = 0;
        }
    }
}