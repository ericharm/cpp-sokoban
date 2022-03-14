#ifdef BASETEST_H
#define BASETEST_H

class BaseTest {

  public:
    BaseTest() {};
    virtual ~BaseTest() = default;
    virtual void run() = 0;

}

#endif // 
