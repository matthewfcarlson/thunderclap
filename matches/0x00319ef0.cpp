class Thing_319ef0 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x8c];
    int flag;
    void Change(int, int*);
    void Target();
};
void Thing_319ef0::Target() {
    if (flag == 0) {
        if (state == 2) {
            state = 0;
            Change(3, &state);
        }
        flag = 1;
    }
}