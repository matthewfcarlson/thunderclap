struct Obj_2f2cb0 {
    int pad[3];
    int data[509];
    int end;
    void finish();
    void target();
};
void Obj_2f2cb0::target() {
    int* q = data;
    int n = 64;
    do {
        q[-3] = 0;
        q[-2] = 0;
        q[-1] = 0;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q += 8;
    } while (--n);
    end = 0;
    finish();
}