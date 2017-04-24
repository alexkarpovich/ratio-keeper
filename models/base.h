#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QDateTime>

class Base : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QDateTime createdAt READ getCreatedAt)
    Q_PROPERTY(QDateTime updatedAt READ getUpdatedAt)

protected:
    QDateTime _createdAt;
    QDateTime _updatedAt;
public:
    explicit Base(QObject *parent = 0);

    QDateTime getCreatedAt();
    QDateTime getUpdatedAt();
    void setCreatedAt(QDateTime createdAt);
    void setUpdatedAt(QDateTime updatedAt);
};

#endif // BASE_H
