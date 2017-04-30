#ifndef USER_H
#define USER_H

#include "base_entity.h"

class User : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername)
    Q_PROPERTY(QString email READ getEmail WRITE setEmail)
    Q_PROPERTY(QString firstName READ getFirstName WRITE setFirstName)
    Q_PROPERTY(QString lastName READ getLastName WRITE setLastName)
    Q_PROPERTY(bool active READ isActive WRITE setActive)
protected:
    QString _username;
    QString _email;
    QString _firstName;
    QString _lastName;
    bool _active;
public:
   User(QObject * parent = 0);
   QString getUsername();
   QString getEmail();
   QString getFirstName();
   QString getLastName();
   bool isActive();
   void setUsername(QString username);
   void setEmail(QString email);
   void setFirstName(QString firstName);
   void setLastName(QString lastName);
   void setActive(bool isActive);
   User* save();

   static User* getActiveUser();
   static User *getById(uuid id);

signals:

public slots:
};

#endif // USER_H
