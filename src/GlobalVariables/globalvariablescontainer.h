#ifndef GLOBALVARIABLESCONTAINER_H
#define GLOBALVARIABLESCONTAINER_H

#include <QObject>
#include <QQmlListProperty>
#include <QVector>
#include "globalvariable.h"
class GlobalVariablesContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<GlobalVariable> globalVariables READ globalVariables)
public:
    explicit GlobalVariablesContainer(QObject *parent = nullptr);

    QQmlListProperty<GlobalVariable> globalVariables();
    void appendGlobalVariable(GlobalVariable*);
    int globalVariableCount() const;
    GlobalVariable *globalVariable(int) const;
    void clearGlobalVariables();
private:
    static void appendGlobalVariable(QQmlListProperty<GlobalVariable>*, GlobalVariable*);
    static int globalVariableCount(QQmlListProperty<GlobalVariable>*);
    static GlobalVariable* globalVariable(QQmlListProperty<GlobalVariable>*, int);
    static void clearGlobalVariables(QQmlListProperty<GlobalVariable>*);


   QList<GlobalVariable *> m_globalVariables;
};

#endif // GLOBALVARIABLESCONTAINER_H
