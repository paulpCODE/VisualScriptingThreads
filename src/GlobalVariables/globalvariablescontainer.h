#ifndef GLOBALVARIABLESCONTAINER_H
#define GLOBALVARIABLESCONTAINER_H

#include <QObject>
#include "globalvariable.h"
class GlobalVariablesContainer : public QObject
{
    Q_OBJECT
public:
    explicit GlobalVariablesContainer(QObject *parent = nullptr);

signals:

};

#endif // GLOBALVARIABLESCONTAINER_H
