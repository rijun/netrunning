#ifndef NETLEVEL_H
#define NETLEVEL_H

#include <QString>

class NetLevel
{
public:
    enum class LevelType { PASSWORD, FILE, BLACKICE, OBJECT, UNKNOWN };

    NetLevel(const LevelType type);

    const QString &value() const { return m_value; }
    void setValue(const QString &value) { m_value = value; }

    const QString &app() const { return m_app; }
    void setApp(const QString &app) { m_app = app; }

    QString difficulty() const { return m_difficulty; }
    void setDifficulty(const QString difficulty) { m_difficulty = difficulty; }

private:
    LevelType m_levelType;
    QString m_value;
    QString m_app;
    QString m_difficulty;
};

#endif // NETLEVEL_H
