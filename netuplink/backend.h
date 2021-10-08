#ifndef BACKEND_H
#define BACKEND_H

#include "netmap.h"

class Backend
{
public:
    Backend();
    ~Backend();

private:
    NetMap *m_net;
};

#endif // BACKEND_H
