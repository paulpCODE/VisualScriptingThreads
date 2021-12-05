#include "globalvariablescontainer.h"

GlobalVariablesContainer::GlobalVariablesContainer(QObject *parent) : QObject(parent)
{
    m_globalVariables.append(new GlobalVariable(QStringLiteral("a"),1));
    m_globalVariables.append(new GlobalVariable(QStringLiteral("b"),1));
    m_globalVariables.append(new GlobalVariable(QStringLiteral("c"),3));

}

QQmlListProperty<GlobalVariable> GlobalVariablesContainer::globalVariables()
{
    return QQmlListProperty<GlobalVariable>(this,& m_globalVariables);
}
//&GlobalVariablesContainer::appendGlobalVariable,
//&GlobalVariablesContainer::globalVariableCount,
//&GlobalVariablesContainer::globalVariable,
//&GlobalVariablesContainer::clearGlobalVariables)


void GlobalVariablesContainer::appendGlobalVariable(GlobalVariable *var)
{
    m_globalVariables.append(var);
}

int GlobalVariablesContainer::globalVariableCount() const
{
    return m_globalVariables.count();
}

GlobalVariable *GlobalVariablesContainer::globalVariable(int index) const
{
    return m_globalVariables.at(index);
}

void GlobalVariablesContainer::clearGlobalVariables()
{
    m_globalVariables.clear();
}

void GlobalVariablesContainer::appendGlobalVariable(QQmlListProperty<GlobalVariable> * list, GlobalVariable * var)
{
     reinterpret_cast< GlobalVariablesContainer* >(list->data)->appendGlobalVariable(var);
}

int GlobalVariablesContainer::globalVariableCount(QQmlListProperty<GlobalVariable> * list)
{
   return reinterpret_cast< GlobalVariablesContainer* >(list->data)->globalVariableCount();
}

GlobalVariable *GlobalVariablesContainer::globalVariable(QQmlListProperty<GlobalVariable> * list, int i)
{
   return reinterpret_cast< GlobalVariablesContainer* >(list->data)->globalVariable(i);
}

void GlobalVariablesContainer::clearGlobalVariables(QQmlListProperty<GlobalVariable> * list)
{
    reinterpret_cast< GlobalVariablesContainer* >(list->data)->clearGlobalVariables();
}
