#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>
using namespace std;

class Buffer
{
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class LimitedBuffer, by extending Buffer
// Write your code here

class LimitedBuffer : public Buffer
{
private:
    unsigned int cap;
    int value;
    vector<int> buffer;

public:
    LimitedBuffer(unsigned int cap, int value);
    ~LimitedBuffer();
    void write(int v);
    int read();
    unsigned int occupancy();
};

#endif /* EX04_LIBRARY_H_ */
