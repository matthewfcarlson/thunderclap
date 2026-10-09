class Subject {
  public:
    int GetState();
    void OnGlobal();
};
class Obj {
  public:
    char pad[4];
    char b4;
    char pad2[0x24 - 5];
    char b24;
    char pad3[0xaec - 0x25];
    Subject* field;
    char flag;
    void OnState();
    void OnOther(Subject*);
    void Step1();
    void Step2();
    void Step3();
    void Step4();
    void Step5();
    void Step6();
    void Run();
};
extern "C" unsigned char gFlag;
void Obj::Run() {
    if (field) {
        int r = field->GetState();
        flag = 1;
        if (r == 3)
            OnState();
        else if (gFlag)
            field->OnGlobal();
        else
            OnOther(field);
    }
    Step1();
    Step2();
    Step3();
    Step4();
    Step5();
    Step6();
    b4 = 0;
    b24 = 0;
}