﻿#ifndef GLOBALVARIABLESCONTAINER_H
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

    void timerEvent(QTimerEvent *) {
           m_globalVariables[1]->setName(m_globalVariables[1]->name() + QStringLiteral("C++"));
       }

public slots:
    // FROM QMl
    void createGlobalVariable(const QString& newName,int newValue);
    void deleteGlobalVariable(const QString& variableNameToDelete);
private:

   QList<GlobalVariable *> m_globalVariables;

};

#endif // GLOBALVARIABLESCONTAINER_H