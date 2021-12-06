#ifndef GLOBALVARIABLESCONTAINER_H
#define GLOBALVARIABLESCONTAINER_H

#include <QObject>
#include <QQmlListProperty>
#include <QVector>
#include <QDebug>
#include "globalvariable.h"
class GlobalVariablesContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<GlobalVariable> globalVariables READ globalVariables CONSTANT)
public:
    explicit GlobalVariablesContainer(QObject *parent = nullptr);

    QQmlListProperty<GlobalVariable> globalVariables();

    //for test purposes. delete this later
    void timerEvent(QTimerEvent *) {
           m_globalVariables[1]->setName(m_globalVariables[1]->name() + QStringLiteral("C++"));
       }



public slots:
    // FROM QMl
    void createGlobalVariable(const QString& newName,int newValue);
    void deleteGlobalVariable(const QString& variableNameToDelete);
    // be careful in qml, if not successful. Maybe need to emit signal if not successfull
    void changeGlobalVariable(const QString& oldName,const QString& newName,int newValue);
    // call when assigning to node
    void increaseUsageCounter(const QString& name);
    // call when global variable is no more used in node
    void decreaseUsageCounter(const QString& name);
    GlobalVariable* globalVariableByName(const QString& name);
private:

   QList<GlobalVariable *> m_globalVariables;

};

#endif // GLOBALVARIABLESCONTAINER_H
