#include "netmap.h"
#include "netlevel.h"

#include <iostream>
#include <QDebug>

NetMap::NetMap()
{

}

bool NetMap::loadNet(QIODevice *device)
{
    if (!m_doc.setContent(device)) {
        device->close();
        return false;
    }

    QDomElement docElem = m_doc.documentElement();
    if (docElem.tagName() != QLatin1String("net")) {
        return false;
    }

    QDomNodeList levelList = docElem.elementsByTagName("level");
    if (levelList.length() == 0) {
        return false;
    }

    for (int i = 0; i < levelList.length(); ++i) {
        const QDomElement levelElement = levelList.item(i).toElement();

        NetLevel::LevelType levelType = readLevel(levelElement.attribute("type"));
        NetLevel level = NetLevel(levelType);
        m_net.append(level);

        for(QDomNode n = levelElement.firstChild(); !n.isNull(); n = n.nextSibling())
        {
            QDomElement e = n.toElement();
            if (!e.isNull()) {
                if (e.tagName() == QLatin1String("value")) {
                    m_net.last().setValue(e.text());
                } else if (e.tagName() == QLatin1String("app")) {
                    m_net.last().setApp(e.text());
                } else if (e.tagName() == QLatin1String("dv")) {
                    m_net.last().setDifficulty(e.text());
                }
            }
        }
    }

    return true;
}

NetLevel::LevelType NetMap::readLevel(const QString &type) const
{
    NetLevel::LevelType levelType;

    if (type == QLatin1String("password")) {
        levelType = NetLevel::LevelType::PASSWORD;
    } else if (type == QLatin1String("file")) {
        levelType = NetLevel::LevelType::FILE;
    } else if (type == QLatin1String("blackice")) {
        levelType = NetLevel::LevelType::BLACKICE;
    } else if (type == QLatin1String("object")) {
        levelType = NetLevel::LevelType::OBJECT;
    } else {
        levelType = NetLevel::LevelType::UNKNOWN;
    }

    return levelType;
}

void NetMap::printNet()
{
    for (const NetLevel &level : qAsConst(m_net)) {
        QString output = QString("%1\t%2\t%3").arg(
                    level.value(),
                    level.app(),
                    level.difficulty());
        std::cout << output.toStdString() << std::endl;
    }
}
