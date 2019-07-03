#include "get_url_pix.h"
#include "ui_get_url_pix.h"
#include <QDebug>
#include <QEventLoop>
get_url_pix::get_url_pix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::get_url_pix)
{
    ui->setupUi(this);

    QObject::connect(ui->url_down,SIGNAL(clicked()),this,SLOT(on_url_down_clicked));
}

get_url_pix::~get_url_pix()
{
    delete ui;
}

bool downIURL_to_picture(const QString &url, const QString &fileName)
{
    //构造请求
    QNetworkAccessManager manager;
    QNetworkRequest request;
    request.setUrl(url);
    // 发送请求
    QNetworkReply *reply = manager.get(request);
    //开启一个局部的事件循环，等待响应结束，退出
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    //判断是否出错
    if (reply->error() != QNetworkReply::NoError)
    {
        return false;
    }
    //SAVE FILE
    QFile f(fileName);
    if(!f.open(QIODevice::WriteOnly))
        return false;
    f.write(reply->readAll());
    f.close();
    delete reply;
    return true;
 }

void get_url_pix::on_url_down_clicked()
{
    QDateTime datetime;
    QString timestr=datetime.currentDateTime().toString("yyyyMMddHHmmss");
    QString fileName = "/home/llw/Pictures/" + timestr + ".jpg";//指定文件夹路径
    qDebug() << "file:" << fileName << endl;
    QString url_name= ui->url_text->text();
    qDebug() << "name:" << url_name << endl;
     downIURL_to_picture(url_name,fileName);
}

