#include "backend.h"

#include <iostream>
#include <QFile>

Backend::Backend()
{
    m_net = new NetMap();

    QFile file("../test_map.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Could not open net definition. Exiting..." << std::endl;
        exit(2);
    }

    if (!m_net->loadNet(&file)) {
        // std::cerr << "Parse error in net file: " << m_net->errorString().toStdString() << std::endl;
        exit(1);
    } else {
         m_net->printNet();
    }

    exit(0);
}

Backend::~Backend()
{
    delete m_net;
}
