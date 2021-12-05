#include "globalvariable.h"
#include <QDebug>

GlobalVariable::GlobalVariable(const QString &name,int value, QObject *parent) : QObject(parent)
{
    m_name = name;
    m_value = value;
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
