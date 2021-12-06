#include "globalvariable.h"
#include <QDebug>

GlobalVariable::GlobalVariable(const QString &name,int value, QObject *parent) : QObject(parent)
{
    setName(name);
    setValue(value);
    mutex = new QMutex();
}

const QString &GlobalVariable::name() const
{
    return m_name;
}

void GlobalVariable::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

int GlobalVariable::value() const
{
    return m_value;
}

void GlobalVariable::setValue(int newValue)
{

    if (m_value == newValue)
        return;
    else if (newValue<0 || newValue > 2147483647) {
        qDebug()<<"Wrong variable value. should be 0..2^31-1 \n";
        return;
    }
    m_value = newValue;
    emit valueChanged();
}

QString GlobalVariable::convertToQString(){
    return QString(m_name + " : " +  QString::number(m_value));
}

int GlobalVariable::usageCounter() const
{
    return m_usageCounter;
}

void GlobalVariable::setUsageCounter(int newUsageCounter)
{
    if (m_usageCounter == newUsageCounter)
        return;
    m_usageCounter = newUsageCounter;
    emit usageCounterChanged();
}
