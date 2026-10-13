class TrackFactoryCasterTemplate {
  public:
    void* vptr;
    void* mObj;
    TrackFactoryCasterTemplate();
    TrackFactoryCasterTemplate* Self();
};
TrackFactoryCasterTemplate::TrackFactoryCasterTemplate() {
    void* q = &vptr;
    *(char**)q = (char*)0x3fcbdc;
}
TrackFactoryCasterTemplate* TrackFactoryCasterTemplate::Self() {
    return this;
}
