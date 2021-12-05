#include "globalvariablescontainer.h"

GlobalVariablesContainer::GlobalVariablesContainer(QObject *parent) : QObject(parent)
{
    m_globalVariables.append(new GlobalVariable(QStringLiteral("a"),1));
    m_globalVariables.append(new GlobalVariable(QStringLiteral("b"),1));
    m_globalVariables.append(new GlobalVariable(QStringLiteral("c"),3));
    startTimer(5000);
}

QQmlListProperty<GlobalVariable> GlobalVariablesContainer::globalVariables()
{
    return QQmlListProperty<GlobalVariable>(this,& m_globalVariables);
}


