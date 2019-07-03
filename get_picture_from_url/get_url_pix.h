#ifndef GET_URL_PIX_H
#define GET_URL_PIX_H

#include <QWidget>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>
namespace Ui {
class get_url_pix;
}

class get_url_pix : public QWidget
{
    Q_OBJECT

    QFile *m_file;
    bool m_isReady;
public:
    explicit get_url_pix(QWidget *parent = 0);
    ~get_url_pix();

//    void downloadFileFromURL(const QString &url, const QString &filePath);

private slots:
    void on_url_down_clicked();

private:
    Ui::get_url_pix *ui;
//    void onDownloadFileComplete(QNetworkReply *reply);
};
bool downIURL_to_picture(const QString &url, const QString &fileName);

#endif // GET_URL_PIX_H
