#pragma once
#include <QObject>
#include <QString>
#include <QtDBus>

class WiFiSSID : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentSSID READ currentSSID NOTIFY currentSSIDChanged)
    Q_PROPERTY(QString savedSSID READ savedSSID NOTIFY savedSSIDChanged)
public:
    explicit WiFiSSID(QObject *parent = nullptr) : QObject(parent) {}

    QString currentSSID() const { return m_currentSSID; }
    QString savedSSID()   const { return m_savedSSID; }

    Q_INVOKABLE void fetchCurrentSSID();
    Q_INVOKABLE void saveCurrentSSID();
    Q_INVOKABLE bool checkSavedSSID();

signals:
    void currentSSIDChanged();
    void savedSSIDChanged();

private:
    QString m_currentSSID;
    QString m_savedSSID;
};
