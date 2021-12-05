#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <QObject>
#include <QMutex>

class GlobalVariable : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit GlobalVariable(const QString &name,int value, QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

    int value() const;
    void setValue(int newValue);

signals:

    void nameChanged();

    void valueChanged();

public:
    QMutex *mutex;
private:

    QString m_name;
    int m_value;

};

#endif // GLOBALVARIABLE_H
