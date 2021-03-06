#include "globalvariablescontainer.h"

GlobalVariablesContainer::GlobalVariablesContainer(QObject *parent) : QObject(parent)
{
    //for test purposes. change this later


    connect(this,&GlobalVariablesContainer::globalVariablesDataChanged,this,&GlobalVariablesContainer::updateQstringlistGlobalVariableModel);
    connect(this,&GlobalVariablesContainer::globalVariablesDataChanged,this,&GlobalVariablesContainer::updateSimpleVariablesNamesModel);


    createGlobalVariable(QStringLiteral("a"),1);
    createGlobalVariable(QStringLiteral("b"),1);
    createGlobalVariable(QStringLiteral("c"),3);

    //for test purposes. change this later
 //   updateQstringlistGlobalVariableModel();

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
    emit globalVariablesDataChanged();
}

void GlobalVariablesContainer::deleteGlobalVariable(const QString &variableNameToDelete)
{

    QList<GlobalVariable*>::iterator it = m_globalVariables.begin();
    while (it != m_globalVariables.end())
    {
        if ((*it)->name()== variableNameToDelete )
        {
            if((*it)->usageCounter()>0)
            {
                qDebug()<<"Variable "<<variableNameToDelete<<"is used somewhere. Can't be deleted now \n";
                return;
            }
            else{
                qDebug()<<"Variable "<< (*it)->name()<<"deleted \n";
                it = m_globalVariables.erase(it);
                emit globalVariablesDataChanged();
                return;
            }
        }
        else
            ++it;
    }
    qDebug()<<"Variable "<<variableNameToDelete<<"don't exists \n";



}

void GlobalVariablesContainer::changeGlobalVariable(const QString &oldName, const QString &newName, int newValue)
{
    //    if(oldName!= newName){
    //        for(const auto &i: m_globalVariables){
    //            if(i->name() == newName){
    //                qDebug()<<"Variable with desired new name {"<<newName<<"}already exists \n";
    //                return;
    //            }
    //        }
    //    }
    for(const auto &i: m_globalVariables){
        //if can find variable with old name
        if(i->name() == oldName){
            // if used somewhere - return
            if(i->usageCounter()>0){
                qDebug()<<"Variable "<<oldName<<"was used somewhere. Can't be changed now \n";
                return;
            }
            // changing variable
            i->setName(newName);
            i->setValue(newValue);
            emit globalVariablesDataChanged();
            return;
        }
    }
    qDebug()<<"Variable with old name{"+ oldName + "}don't exist  \n";
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

GlobalVariable *GlobalVariablesContainer::globalVariableByName(const QString &name)
{
    for(int i =0;i<m_globalVariables.size();i++){
        if(m_globalVariables[i]->name() == name){

            return m_globalVariables[i];
        }
    }
    qDebug()<<"Variable"<<name<<"do not exists \n";
    return nullptr;
}

GlobalVariable *GlobalVariablesContainer::globalVariablebyIndex(int index)
{
    if (index > m_qstringlistGlobalVariableModel.size()){
        qDebug()<<"index"<<index<<"out of range \n";
        return nullptr;
    }
    QString temp = m_qstringlistGlobalVariableModel[index];
    temp.replace(QString(" "), QString(""));
    QStringList myStringList = temp.split(':');

    if(myStringList.last() == QString::number(m_globalVariables[index]->value())){
        return m_globalVariables[index];
    }

    qDebug()<<"Global variable by index"<<index<<"do not exists \n";
    return nullptr;
}

QString GlobalVariablesContainer::globalVariableNameByIndex(int index)
{

    if (index > m_qstringlistGlobalVariableModel.size()){
        qDebug()<<"index"<<index<<"out of range \n";
        return nullptr;
    }
    auto tempName = m_globalVariables[index]->name();

    QString temp = m_qstringlistGlobalVariableModel[index];
    temp.replace(QString(" "), QString(""));
    QStringList myStringList = temp.split(':');

    if(myStringList.last() == QString::number(m_globalVariables[index]->value())){
        return tempName;
    }

    qDebug()<<"Global variable by index"<<index<<"do not exists \n";
    return nullptr;
}


void GlobalVariablesContainer::updateQstringlistGlobalVariableModel()
{
    QStringList newList;
    for(const auto &i: m_globalVariables){
        newList.push_back(i->convertToQString());
    }
    m_qstringlistGlobalVariableModel = newList;
    emit qstringlistGlobalVariableModelChanged();
}

void GlobalVariablesContainer::updateSimpleVariablesNamesModel()
{
    QStringList newList;
    for(const auto &i: m_globalVariables){
        newList.push_back(i->name());
    }
    m_simpleVariablesNamesModel = newList;
    emit simpleVariablesNamesModelChanged();
   // setSimpleVariablesNamesModel(newList);
}



const QStringList &GlobalVariablesContainer::qstringlistGlobalVariableModel() const
{
    return m_qstringlistGlobalVariableModel;
}

void GlobalVariablesContainer::setQstringlistGlobalVariableModel(const QStringList &newQstringlistGlobalVariableModel)
{
    if (m_qstringlistGlobalVariableModel == newQstringlistGlobalVariableModel)
        return;
    m_qstringlistGlobalVariableModel = newQstringlistGlobalVariableModel;
    emit qstringlistGlobalVariableModelChanged();
}

const QStringList &GlobalVariablesContainer::simpleVariablesNamesModel() const
{
    return m_simpleVariablesNamesModel;
}

void GlobalVariablesContainer::setSimpleVariablesNamesModel(const QStringList &newSimpleVariablesNamesModel)
{
    if (m_simpleVariablesNamesModel == newSimpleVariablesNamesModel)
        return;
    m_simpleVariablesNamesModel = newSimpleVariablesNamesModel;
    emit simpleVariablesNamesModelChanged();
}
