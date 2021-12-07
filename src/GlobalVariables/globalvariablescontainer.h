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
    Q_PROPERTY(QStringList qstringlistGlobalVariableModel READ qstringlistGlobalVariableModel WRITE setQstringlistGlobalVariableModel NOTIFY qstringlistGlobalVariableModelChanged)
public:
    explicit GlobalVariablesContainer(QObject *parent = nullptr);
    const QStringList &qstringlistGlobalVariableModel() const;
    void setQstringlistGlobalVariableModel(const QStringList &newQstringlistGlobalVariableModel);

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
    //by index from qstringlistmodel
    GlobalVariable* globalVariablebyIndex(int index);
    //Get Variable Name By index from qstringlistmodel
    QString globalVariableNameByIndex(int index);
    void updateQstringlistGlobalVariableModel();
signals:
    void qstringlistGlobalVariableModelChanged();
    void globalVariablesDataChanged();
private:

   QList<GlobalVariable *> m_globalVariables;

   QStringList m_qstringlistGlobalVariableModel;
};

#endif // GLOBALVARIABLESCONTAINER_H
