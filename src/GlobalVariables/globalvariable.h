#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <QObject>
#include <QMutex>
#include <QString>
class GlobalVariable : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int usageCounter READ usageCounter WRITE setUsageCounter NOTIFY usageCounterChanged)
public:
    explicit GlobalVariable(const QString &name,int value, QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

    int value() const;
    void setValue(int newValue);
    QString convertToQString();
signals:

    void nameChanged();

    void valueChanged();

    void usageCounterChanged();

public:
    QMutex *mutex;
    int usageCounter() const;
    void setUsageCounter(int newUsageCounter);

private:

    QString m_name;
    int m_value;

    int m_usageCounter;
};
Q_DECLARE_METATYPE(GlobalVariable);
#endif // GLOBALVARIABLE_H
