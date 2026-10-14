class SimpleFrameController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual float vfunc_11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    char pad[0x3c - 4];
    struct Data {
        char pad[0x10];
        float value;
    }* data;
};
extern const float zero_284da0;
float SimpleFrameController::vfunc_11() {
    if (data)
        return data->value;
    return zero_284da0;
}
