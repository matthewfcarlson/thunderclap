class CompletionEventRequest_2735d0 {
  public:
    virtual void F0();
    virtual void F1();
    virtual ~CompletionEventRequest_2735d0() throw();
};
class CompletionEventRequest : public CompletionEventRequest_2735d0 {
  public:
    char pad[0x0c - sizeof(CompletionEventRequest_2735d0)];
    CompletionEventRequest_2735d0* mRequest;
    virtual ~CompletionEventRequest() throw();
};
CompletionEventRequest_2735d0::~CompletionEventRequest_2735d0() throw() {}
CompletionEventRequest::~CompletionEventRequest() throw() {
    mRequest->F1();
}
