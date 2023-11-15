#ifndef TWILIOEXAMPLE_H
#define TWILIOEXAMPLE_H




#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrlQuery>

class TwilioExample : public QObject
{
    Q_OBJECT

public:
    explicit TwilioExample(QObject *parent = nullptr);
    void sendMessage(const QString , const QString , const QString );

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString accountSid;
};



#endif // TWILIOEXAMPLE_H
