extern "C" char DAT_0042d9dc[];
class Controller {
  public:
    char pad[0x40];
    int a;
    int pad44;
    int b;
    int c;
    int d;
    int e;
};
void Init();
Controller* __fastcall Target(Controller* self) {
    Init();
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4c) = 0;
    *(int*)self = ((int)DAT_0042d9dc);
    *(int*)((char*)self + 0x50) = 0x2a5260;
    return self;
}