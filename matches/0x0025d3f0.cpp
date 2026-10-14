int Check(int);
class Obj_25d3f0 {
  public:
    char p[0x34];
    int value;
    char q[0x20];
    int state;
    char flag;
    void Take(int*);
};
void Obj_25d3f0::Take(int* out) {
    if (out) {
        int v = value;
        if (v != 0) {
            int r = Check(v);
            if (r == 2 && !flag) {
                *out = value;
                value = 0;
                state = 5;
                return;
            }
        } else {
            *out = 0;
        }
    }
    state = 5;
}