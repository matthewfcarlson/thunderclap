extern int gValue;
class ControllerBuffer {
  public:
    int vptr;
    int vptr4;
    int ref;
    int enabled;
    int a;
    int b;
    int c;
    int d;
    int e;
    int pad;
    int f;
    ControllerBuffer(int);
};
void InitBase();
ControllerBuffer::ControllerBuffer(int value) {
    vptr = 0x42b6b0;
    vptr4 = 0x42afa8;
    ref = *(int*)0x4cdbb0;
    InitBase();
    vptr = 0x42b688;
    vptr4 = 0x42b680;
    enabled = 1;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    pad = 0;
    f = value;
    InitBase();
}