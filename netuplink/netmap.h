#ifndef NETMAP_H
#define NETMAP_H

#include <QDomDocument>
#include <QVector>

#include "netlevel.h"

class NetMap
{
public:
    NetMap();

    bool loadNet(QIODevice *device);
    QString errorString() const;

    void printNet();

private:
    void readXml();
    NetLevel::LevelType readLevel(const QString &type) const;
    void readValue();
    void readApp();
    void readDifficultyValue();

    QDomDocument m_doc;
    QVector<NetLevel> m_net;
};

#endif // NETMAP_H
