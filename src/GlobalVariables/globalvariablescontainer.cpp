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
        if (i.next()->name() == variableNameToDelete )
            if(i.next()->usageCounter()>0){
                qDebug()<<"Variable "<<variableNameToDelete<<"is used somewhere. Can't be deleted now \n";
                return;
            }
            i.next()->deleteLater();
            i.remove();
        return;
    }
    qDebug()<<"Variable "<<variableNameToDelete<<"don't exists \n";


}

void GlobalVariablesContainer::changeGlobalVariable(const QString &oldName, const QString &newName, int newValue)
{

    for(const auto &i: m_globalVariables){
        if(i->name() == newName){
            qDebug()<<"Variable with desired new name {"<<newName<<"}already exists \n";
            return;
        }
    }
    for(const auto &i: m_globalVariables){
        //if can find variable with old name
        if(i->name() == oldName){
            // if used somewhere - return
            if(i->usageCounter()>0){
                qDebug()<<"Variable "<<oldName<<"is used somewhere. Can't be changed now \n";
                return;
            }
            // changing variable
            i->setName(newName);
            i->setValue(newValue);
            return;
        }
    }
      qDebug()<<"something wrong in changeGlobalVariable() old name{" + oldName + "} new name {" + newName +"}   \n";
}

void GlobalVariablesContainer::increaseUsageCounter(const QString &name)
{
    for(const auto &i: m_globalVariables){
        if(i->name() == name){
            i->setUsageCounter(i->usageCounter()+1);
            return;
        }
    }
    qDebug()<<"Variable "<<name<<"don't exists \n";

}

void GlobalVariablesContainer::decreaseUsageCounter(const QString &name)
{
    for(const auto &i: m_globalVariables){
        if(i->name() == name){
            i->setUsageCounter(i->usageCounter()-1);
            return;
        }
    }
    qDebug()<<"Variable "<<name<<"don't exists \n";

}


