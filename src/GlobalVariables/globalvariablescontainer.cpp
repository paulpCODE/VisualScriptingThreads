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
    return QQmlListProperty<GlobalVariable>(this,&m_globalVariables);
}

void GlobalVariablesContainer::createGlobalVariable(const QString& newName,int newValue)
{
    for(const auto &i: m_globalVariables){
        if(i->name() == newName){
            qDebug()<<"Variable "<<newName<<"already exists \n";
            return;
        }
    }
    m_globalVariables.append(new GlobalVariable(newName,newValue));
}

void GlobalVariablesContainer::deleteGlobalVariable(const QString &variableNameToDelete)
{
    QMutableListIterator<GlobalVariable*> i(m_globalVariables);
    while (i.hasNext()) {
        if (i.next()->name() == variableNameToDelete)
            i.next()->deleteLater();
            i.remove();
        return;
    }
    qDebug()<<"Variable "<<variableNameToDelete<<"don't exists \n";


}


