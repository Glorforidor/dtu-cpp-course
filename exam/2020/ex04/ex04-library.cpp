#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods

LimitedBuffer::LimitedBuffer(unsigned int cap, int value)
{
    this->cap = cap;
    this->value = value;
}

LimitedBuffer::~LimitedBuffer(){};

void LimitedBuffer::write(int v)
{
    // Do not exceed capacity.
    if (occupancy() == cap)
    {
        return;
    }

    buffer.push_back(v);
}

int LimitedBuffer::read()
{
    // If non occupies the buffer, return default value.
    if (occupancy() == 0)
    {
        return value;
    }

    // I did not know if I could introduce a new import in the header file.
    // So I use the already imported vector in it.
    // Otherwise I might have gone with #include <deque>
    // for efficiency and ease.

    // Take out the front of the vector.
    int v = buffer.front();
    // Erase the front of the vector.
    buffer.erase(buffer.begin());

    return v;
}

unsigned int LimitedBuffer::occupancy()
{
    // The buffer is a vector object and the vector size method tells the
    // occupancy for us.
    return buffer.size();
}

// Do not modify
Buffer::~Buffer()
{
    // Empty destructor
}
