class Request {
  public:
    virtual void F0();
    virtual void F1();
    virtual ~Request() throw();
};
class CompletionEventRequest : public Request {
  public:
    char pad[0x0c - sizeof(Request)];
    Request* mRequest;
    virtual ~CompletionEventRequest() throw();
};
Request::~Request() throw() {}
CompletionEventRequest::~CompletionEventRequest() throw() {
    mRequest->F1();
}
