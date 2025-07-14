#pragma once
#include <QObject>
#include <QString>

class WiFiBSSID : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentBSSID READ currentBSSID NOTIFY currentBSSIDChanged)
    Q_PROPERTY(QString savedBSSID   READ savedBSSID   NOTIFY savedBSSIDChanged)

public:
    explicit WiFiBSSID(QObject *parent = nullptr) : QObject(parent) {}

    QString currentBSSID() const { return m_currentBSSID; }
    QString savedBSSID()   const { return m_savedBSSID;   }

    Q_INVOKABLE void fetchCurrentBSSID();
    Q_INVOKABLE void saveCurrentBSSID();
    Q_INVOKABLE bool checkSavedBSSID();

signals:
    void currentBSSIDChanged();
    void savedBSSIDChanged();

private:
    QString m_currentBSSID;
    QString m_savedBSSID;
};
