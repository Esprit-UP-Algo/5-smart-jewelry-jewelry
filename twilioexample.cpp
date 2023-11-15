#include "twilioexample.h"


#include <QNetworkReply>

TwilioExample::TwilioExample(QObject *parent)
    : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    accountSid = "AC030f52e28f3bf09706a1698bbc6b228b";  // Replace with your Twilio account SID
}

void TwilioExample::sendMessage(const QString to, const QString from, const QString body)
{
    connect(manager, &QNetworkAccessManager::finished, this, &TwilioExample::onReplyFinished);

    QNetworkRequest request(QUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json"));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

    QUrlQuery postData;
    postData.addQueryItem("To", to);
    postData.addQueryItem("From", from);
    postData.addQueryItem("Body", body);

    QByteArray postDataBytes = postData.toString(QUrl::FullyEncoded).toUtf8();
    manager->post(request, postDataBytes);
}

void TwilioExample::onReplyFinished(QNetworkReply *reply)
{
    // Handle the reply here if needed
    reply->deleteLater();
}
