extern void* vReq[];
extern void* vCE[];
class Obj_274ba0 {
  public:
    virtual void A();
};
extern void FUN_002705f0();
struct CompletionEventRequest_274ba0 {
    void* vf;
    int p4;
    int p8;
    Obj_274ba0* pC;
    CompletionEventRequest_274ba0(int, Obj_274ba0*);
};
CompletionEventRequest_274ba0::CompletionEventRequest_274ba0(int a, Obj_274ba0* b) {
    vf = vReq;
    p4 = 0;
    FUN_002705f0();
    vf = vCE;
    p8 = a;
    pC = b;
    FUN_002705f0();
    pC->A();
}
