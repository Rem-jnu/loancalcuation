#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDebug>
#include<qmath.h>
#include<qtimer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    int m_mortType;//房贷类型
    int m_claType;//计算方式
    double m_price;//房屋单价
    double m_area;//房屋面积
    int m_percentage;//按揭成数;
    int m_numOfYear;//按揭年数;
    double m_rate;//带块利率
    bool m_repaymentTupe1;//还款方式
    bool m_repaymentTupe2;//还款方式

    double shoufu;
    double yuegong;
    double daikuanzonge;
    double zhifulixi;
    double huankuanzonge;
    int huankuanyueshu;
    double meiyuedijian;

    QTimer* m_timer;
    bool flag;
 public  slots:
    void MortType(int index);//房贷类型槽函数
    void CalType(int index);
    void NumofYear(int index);
    void Percentage(int index);
    void checkSlot1(bool);
    void checkSlot2(bool);
    void pushButtonCal();
    void pushButtonClear();
    void ImageTimerTimeout();
};
#endif // WIDGET_H
