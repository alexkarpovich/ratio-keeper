#ifndef APPUTILITY_H
#define APPUTILITY_H

#include <QDebug>
#include <QObjectList>

class AppUtility
{
public:
    AppUtility();

    template <class T>
    static QObjectList getObjectList(QList<T> list) {
        qDebug() << "AppUtility::getObjectList - ";

        QObjectList objectList;

        foreach (T item, list) {
            objectList.append(item);
        }

        return objectList;
    }

};

#endif // APPUTILITY_H
