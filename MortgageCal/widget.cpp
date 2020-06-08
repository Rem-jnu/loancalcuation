#include "widget.h"
#include "ui_widget.h"
#include<QIcon>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,m_mortType(0)
    ,m_claType(0)
    ,m_numOfYear(0)
    ,m_percentage(0)
{
    ui->setupUi(this);

    setFixedSize(580,440);
    setWindowIcon(QIcon(":/Image/loancalcuation.png"));
    m_repaymentTupe1 = false;
    m_repaymentTupe2 = false;
    //关联信号和槽
    QObject::connect(ui->comboBoxMorType, SIGNAL(currentIndexChanged(int)), this, SLOT(MortType(int)));
    QObject::connect(ui->comboBoxCalType, SIGNAL(currentIndexChanged(int)), this, SLOT(CalType(int)));
    QObject::connect(ui->comboBoxNumofYear, SIGNAL(currentIndexChanged(int)), this, SLOT(NumofYear(int)));
    QObject::connect(ui->comboBoxPercentage, SIGNAL(currentIndexChanged(int)), this, SLOT(Percentage(int)));
    connect(ui->radioButton1,SIGNAL(toggled(bool)),this,SLOT(checkSlot1(bool)));
    connect(ui->radioButton2,SIGNAL(toggled(bool)),this,SLOT(checkSlot2(bool)));
    connect(ui->pushButtonCal, SIGNAL(clicked()), this, SLOT(pushButtonCal()));
    connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(pushButtonClear()));

    m_timer = new QTimer;
    //设置定时器是否为单次触发。默认为 false 多次触发
    m_timer->setSingleShot(false);
   //启动或重启定时器, 并设置定时器时间：毫秒
    m_timer->start(100);
    //定时器触发信号槽
    connect(m_timer, SIGNAL(timeout()), this, SLOT(ImageTimerTimeout()));

    flag = true;
}

Widget::~Widget()
{
    delete m_timer;
    delete ui;
}
void Widget::ImageTimerTimeout()
{
    qDebug()<<m_mortType<<" "<<m_claType;
    if(m_mortType == 0 || m_mortType == 1)//商业贷款和公积金贷款
    {
        if( m_claType == 0)//根据面积、单价计算
        {
            ui->labeldaikuanzonge->setHidden(true);
            ui->lineEditDaikuanzonge->setHidden(true);

            ui->labelfangwudanjia->setHidden(false);
            ui->labelfangwumianji->setHidden(false);
            ui->lineEditarea->setHidden(false);
            ui->lineEditPrice->setHidden(false);


            ui->labelshangdaililv->setHidden(true);
            ui->labelshangdaizonge->setHidden(true);
            ui->labelgongjijindaililv->setHidden(true);
            ui->labelgongjijindaizonge->setHidden(true);
            ui->lineEditshangdaiRate->setHidden(true);
            ui->lineEditshangyedaikuangzonge->setHidden(true);
            ui->lineEditgongjijinRate->setHidden(true);
            ui->lineEditgongjijindaikuanzonge->setHidden(true);

            ui->comboBoxCalType->setHidden(false);
            ui->label_3->setHidden(false);
            ui->label_8->setHidden(false);
            ui->lineEditRate->setHidden(false);
            //
            if(m_repaymentTupe1)
            {
                ui->label_24->setHidden(true);
                ui->label_25->setHidden(true);
                ui->label_22->setHidden(true);
                ui->label_23->setHidden(true);
                ui->shouyuegong->setHidden(true);
                ui->meiyuedijian->setHidden(true);
            ui->label_10->setHidden(false);
            ui->label_16->setHidden(false);
            ui->label_11->setHidden(false);
            ui->label_17->setHidden(false);
            ui->label_12->setHidden(false);
            ui->label_18->setHidden(false);
            ui->label_13->setHidden(false);
            ui->label_19->setHidden(false);
            ui->label_14->setHidden(false);
            ui->label_20->setHidden(false);
            ui->label_15->setHidden(false);
            ui->label_21->setHidden(false);
            ui->shoufu->setHidden(false);
            ui->yuegong->setHidden(false);
            ui->zonge->setHidden(false);
            ui->lixi->setHidden(false);
            ui->huankuanzonge->setHidden(false);
            ui->huankuanyueshu->setHidden(false);
            }
            else if(m_repaymentTupe2)
            {
                ui->label_10->setHidden(false);
                ui->label_16->setHidden(false);
                ui->label_11->setHidden(true);
                ui->label_17->setHidden(true);
                ui->shoufu->setHidden(false);
                ui->yuegong->setHidden(true);
                ui->label_12->setHidden(false);
                ui->label_18->setHidden(false);
                ui->label_13->setHidden(false);
                ui->label_19->setHidden(false);
                ui->label_14->setHidden(false);
                ui->label_20->setHidden(false);
                ui->label_15->setHidden(false);
                ui->label_21->setHidden(false);
                ui->label_24->setHidden(false);
                ui->label_25->setHidden(false);
                ui->label_22->setHidden(false);
                ui->label_23->setHidden(false);
                ui->shouyuegong->setHidden(false);
                ui->meiyuedijian->setHidden(false);
                ui->zonge->setHidden(false);
                ui->lixi->setHidden(false);
                ui->huankuanzonge->setHidden(false);
                ui->huankuanyueshu->setHidden(false);
            }

        }

        if( m_claType == 1)//根据贷款总额计算
        {
            ui->label_6->setHidden(true);
            ui->comboBoxPercentage->setHidden(true);
            ui->labelfangwudanjia->setHidden(true);
            ui->labelfangwumianji->setHidden(true);
            ui->lineEditarea->setHidden(true);
            ui->lineEditPrice->setHidden(true);

            ui->labeldaikuanzonge->setHidden(false);
            ui->lineEditDaikuanzonge->setHidden(false);

            ui->comboBoxCalType->setHidden(false);
            ui->label_3->setHidden(false);
            ui->label_8->setHidden(false);
            ui->lineEditRate->setHidden(false);

            ui->labelshangdaililv->setHidden(true);
            ui->labelshangdaizonge->setHidden(true);
            ui->labelgongjijindaililv->setHidden(true);
            ui->labelgongjijindaizonge->setHidden(true);
            ui->lineEditshangdaiRate->setHidden(true);
            ui->lineEditshangyedaikuangzonge->setHidden(true);
            ui->lineEditgongjijinRate->setHidden(true);
            ui->lineEditgongjijindaikuanzonge->setHidden(true);
            //
            if(m_repaymentTupe1)
            {
                ui->label_24->setHidden(true);
                ui->label_25->setHidden(true);
                ui->label_22->setHidden(true);
                ui->label_23->setHidden(true);
                ui->shouyuegong->setHidden(true);
                ui->meiyuedijian->setHidden(true);
            ui->label_10->setHidden(true);
            ui->label_16->setHidden(true);
            ui->label_11->setHidden(false);
            ui->label_17->setHidden(false);
            ui->label_12->setHidden(false);
            ui->label_18->setHidden(false);
            ui->label_13->setHidden(false);
            ui->label_19->setHidden(false);
            ui->label_14->setHidden(false);
            ui->label_20->setHidden(false);
            ui->label_15->setHidden(false);
            ui->label_21->setHidden(false);
            ui->shoufu->setHidden(true);
            ui->yuegong->setHidden(false);
            ui->zonge->setHidden(false);
            ui->lixi->setHidden(false);
            ui->huankuanzonge->setHidden(false);
            ui->huankuanyueshu->setHidden(false);
            }
            else if(m_repaymentTupe2)
            {
                ui->label_10->setHidden(true);
                ui->label_16->setHidden(true);
                ui->label_11->setHidden(true);
                ui->label_17->setHidden(true);
                ui->shoufu->setHidden(true);
                ui->yuegong->setHidden(true);
                ui->label_12->setHidden(false);
                ui->label_18->setHidden(false);
                ui->label_13->setHidden(false);
                ui->label_19->setHidden(false);
                ui->label_14->setHidden(false);
                ui->label_20->setHidden(false);
                ui->label_15->setHidden(false);
                ui->label_21->setHidden(false);
                ui->label_24->setHidden(false);
                ui->label_25->setHidden(false);
                ui->label_22->setHidden(false);
                ui->label_23->setHidden(false);
                ui->shouyuegong->setHidden(false);
                ui->meiyuedijian->setHidden(false);
                ui->zonge->setHidden(false);
                ui->lixi->setHidden(false);
                ui->huankuanzonge->setHidden(false);
                ui->huankuanyueshu->setHidden(false);
            }

        }
    }

    if( m_mortType == 2 )
    {
        ui->label_6->setHidden(true);
        ui->comboBoxPercentage->setHidden(true);
        ui->labelfangwudanjia->setHidden(true);
        ui->labelfangwumianji->setHidden(true);
        ui->lineEditarea->setHidden(true);
        ui->lineEditPrice->setHidden(true);

        ui->labeldaikuanzonge->setHidden(true);
        ui->lineEditDaikuanzonge->setHidden(true);

        ui->comboBoxCalType->setHidden(true);
        ui->label_3->setHidden(true);
        ui->label_8->setHidden(true);
        ui->lineEditRate->setHidden(true);

        ui->labelshangdaililv->setHidden(false);
        ui->labelshangdaizonge->setHidden(false);
        ui->labelgongjijindaililv->setHidden(false);
        ui->labelgongjijindaizonge->setHidden(false);
        ui->lineEditshangdaiRate->setHidden(false);
        ui->lineEditshangyedaikuangzonge->setHidden(false);
        ui->lineEditgongjijinRate->setHidden(false);
        ui->lineEditgongjijindaikuanzonge->setHidden(false);
       // m_claType=0;
        //
        if(m_repaymentTupe1)
        {
            ui->label_24->setHidden(true);
            ui->label_25->setHidden(true);
            ui->label_22->setHidden(true);
            ui->label_23->setHidden(true);
            ui->shouyuegong->setHidden(true);
            ui->meiyuedijian->setHidden(true);
        ui->label_10->setHidden(true);
        ui->label_16->setHidden(true);
        ui->label_11->setHidden(false);
        ui->label_17->setHidden(false);
        ui->label_12->setHidden(false);
        ui->label_18->setHidden(false);
        ui->label_13->setHidden(false);
        ui->label_19->setHidden(false);
        ui->label_14->setHidden(false);
        ui->label_20->setHidden(false);
        ui->label_15->setHidden(false);
        ui->label_21->setHidden(false);
        ui->shoufu->setHidden(true);
        ui->yuegong->setHidden(false);
        ui->zonge->setHidden(false);
        ui->lixi->setHidden(false);
        ui->huankuanzonge->setHidden(false);
        ui->huankuanyueshu->setHidden(false);
        }
        else if(m_repaymentTupe2)
        {
            ui->label_10->setHidden(true);
            ui->label_16->setHidden(true);
            ui->label_11->setHidden(true);
            ui->label_17->setHidden(true);
            ui->shoufu->setHidden(true);
            ui->yuegong->setHidden(true);
            ui->label_12->setHidden(false);
            ui->label_18->setHidden(false);
            ui->label_13->setHidden(false);
            ui->label_19->setHidden(false);
            ui->label_14->setHidden(false);
            ui->label_20->setHidden(false);
            ui->label_15->setHidden(false);
            ui->label_21->setHidden(false);
            ui->label_24->setHidden(false);
            ui->label_25->setHidden(false);
            ui->label_22->setHidden(false);
            ui->label_23->setHidden(false);
            ui->shouyuegong->setHidden(false);
            ui->meiyuedijian->setHidden(false);
            ui->zonge->setHidden(false);
            ui->lixi->setHidden(false);
            ui->huankuanzonge->setHidden(false);
            ui->huankuanyueshu->setHidden(false);
        }

    }
}

void Widget::MortType(int index)
{
    m_mortType = index;
    qDebug()<<m_mortType;
}

void Widget::CalType(int index)
{
    m_claType = index;
}
void Widget::NumofYear(int index)
{
    m_numOfYear = index;
}

void Widget::Percentage(int index)
{
    m_percentage = index;
}

void Widget::checkSlot1(bool index)
{
    m_repaymentTupe1 = index;
}

void Widget::checkSlot2(bool index)
{
    m_repaymentTupe2 = index;
}
void Widget::pushButtonCal()
{
    //double shoufu;
    //double yuegong;
    //double daikuanzonge;
    //double zhifulixi;
    //double huankuanzonge;
    huankuanyueshu = 12* (25 -m_numOfYear);
    ui->huankuanyueshu->setNum(huankuanyueshu);
    //double meiyuedijian;
    //商业贷款
    if(0 == m_mortType)
    {

        double zonge;
        double price;
        double area;
        double rate;
        //根据面积、单价计算
        if(0 == m_claType)
        {
            if(""!=ui->lineEditRate->text())
            {
                rate = ui->lineEditRate->text().toDouble()*0.01/12;
            }
            if(""!=ui->lineEditPrice->text())
            {
                price = ui->lineEditPrice->text().toDouble();
            }
            if(""!=ui->lineEditarea->text())
            {
                area = ui->lineEditarea->text().toDouble();
            }
            qDebug()<<m_repaymentTupe1 <<" "<<m_repaymentTupe2;
            //等额本息
            if(m_repaymentTupe1)
            {
                zonge = price * area;
                ui->zonge->setText(QString::number(((8-m_percentage * 0.5)/10)*zonge,'f',0));

                double money = ((8-m_percentage * 0.5)/10)*zonge * (rate* qPow(1+rate,(25- m_numOfYear)*12))/(qPow(1+rate,12*(25- m_numOfYear))-1);
                ui->yuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(money*(25- m_numOfYear)*12,'f',0));
                //首付
                ui->shoufu->setText(QString::number((1-((8-m_percentage * 0.5)/10))*zonge,'f',0));
                ui->lixi->setText(QString::number(money*(25- m_numOfYear)*12-((8-m_percentage * 0.5)/10)*zonge,'f',0));

            }
            //等额本金
            else if(m_repaymentTupe2)
            {

                double benjin =  price * area*((8-m_percentage * 0.5)/10);
                double meiyuebenjin = benjin/huankuanyueshu;
                double meiyuedijian = (benjin/huankuanyueshu * rate);
                double meiyuelixi = (benjin -benjin*(1-1)/huankuanyueshu)*rate;


                zonge = price * area;
                ui->zonge->setText(QString::number(((8-m_percentage * 0.5)/10)*zonge,'f',0));

                double money = meiyuebenjin+meiyuelixi;

                ui->shouyuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(benjin+(huankuanyueshu+1)*benjin*rate/2,'f',0));
                //首付
                ui->shoufu->setText(QString::number((1-((8-m_percentage * 0.5)/10))*zonge,'f',0));
                ui->lixi->setText(QString::number((huankuanyueshu+1)*benjin*rate/2,'f',0));
                ui->meiyuedijian->setText(QString::number(meiyuedijian,'f',0));
            }
        }
        //根据贷款总额计算
        else if(1 == m_claType)
        {
            if(""!=ui->lineEditRate->text())
            {
                rate = ui->lineEditRate->text().toDouble()*0.01/12;
            }
            //等额本息
            if(m_repaymentTupe1)
            {
                zonge = ui->lineEditDaikuanzonge->text().toDouble();
                ui->zonge->setText(QString::number(zonge,'f',0));

                double money = zonge * (rate* qPow(1+rate,(25- m_numOfYear)*12))/(qPow(1+rate,12*(25- m_numOfYear))-1);
                ui->yuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(money*(25- m_numOfYear)*12,'f',0));


                ui->lixi->setText(QString::number(money*(25- m_numOfYear)*12-zonge,'f',0));

            }
            //等额本金
            else if(m_repaymentTupe2)
            {


                zonge = ui->lineEditDaikuanzonge->text().toDouble();
                double benjin =  zonge;
                double meiyuebenjin = benjin/huankuanyueshu;
                double meiyuedijian = (benjin/huankuanyueshu * rate);
                double meiyuelixi = (benjin -benjin*(1-1)/huankuanyueshu)*rate;



                ui->zonge->setText(QString::number(zonge,'f',0));

                double money = meiyuebenjin+meiyuelixi;
                ui->shouyuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(benjin+(huankuanyueshu+1)*benjin*rate/2,'f',0));


                ui->lixi->setText(QString::number((huankuanyueshu+1)*benjin*rate/2,'f',0));
                ui->meiyuedijian->setText(QString::number(meiyuedijian,'f',0));
            }
        }
    }
    //公积金贷款
    else if(1 == m_mortType)
    {

        double zonge;
        double price;
        double area;
        double rate;
        //面积、单价计算
        if(0 == m_claType)
        {
            if(""!=ui->lineEditRate->text())
            {
                rate = ui->lineEditRate->text().toDouble()*0.01/12;
            }
            if(""!=ui->lineEditPrice->text())
            {
                price = ui->lineEditPrice->text().toDouble();
            }
            if(""!=ui->lineEditarea->text())
            {
                area = ui->lineEditarea->text().toDouble();
            }
            qDebug()<<m_repaymentTupe1 <<" "<<m_repaymentTupe2;
            //等额本息
            if(m_repaymentTupe1)
            {
                zonge = price * area;
                ui->zonge->setText(QString::number(((8-m_percentage * 0.5)/10)*zonge,'f',0));

                double money = ((8-m_percentage * 0.5)/10)*zonge * (rate* qPow(1+rate,(25- m_numOfYear)*12))/(qPow(1+rate,12*(25- m_numOfYear))-1);
                ui->yuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(money*(25- m_numOfYear)*12,'f',0));
                //首付
                ui->shoufu->setText(QString::number((1-((8-m_percentage * 0.5)/10))*zonge));
                ui->lixi->setText(QString::number(money*(25- m_numOfYear)*12- ((8-m_percentage * 0.5)/10)*zonge,'f',0));

            }
            //等额本金
            else if(m_repaymentTupe2)
            {

                double benjin =  price * area * ((8-m_percentage * 0.5)/10);
                double meiyuebenjin = benjin/huankuanyueshu;
                double meiyuedijian = (benjin/huankuanyueshu * rate);
                double meiyuelixi = (benjin -benjin*(1-1)/huankuanyueshu)*rate;


                zonge = price * area;
                ui->zonge->setText(QString::number(((8-m_percentage * 0.5)/10)*zonge,'f',0));

                double money = meiyuebenjin+meiyuelixi;
                ui->shouyuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(benjin+(huankuanyueshu+1)*benjin*rate/2,'f',0));

                ui->shoufu->setText(QString::number((1-((8-m_percentage * 0.5)/10))*zonge));
                ui->lixi->setText(QString::number((huankuanyueshu+1)*benjin*rate/2,'f',0));
                ui->meiyuedijian->setText(QString::number(meiyuedijian,'f',0));
            }
        }
        //总额计算
        else if(1 == m_claType)
        {
            if(""!=ui->lineEditRate->text())
            {
                rate = ui->lineEditRate->text().toDouble()*0.01/12;
            }
            //等额本息
            if(m_repaymentTupe1)
            {
                zonge = ui->lineEditDaikuanzonge->text().toDouble();
                ui->zonge->setText(QString::number(zonge,'f',0));

                double money = (1)*zonge * (rate* qPow(1+rate,(25- m_numOfYear)*12))/(qPow(1+rate,12*(25- m_numOfYear))-1);
                ui->yuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(money*(25- m_numOfYear)*12,'f',0));

                ui->lixi->setText(QString::number(money*(25- m_numOfYear)*12-zonge,'f',0));

            }
            //等额本金
            else if(m_repaymentTupe2)
            {
                zonge = ui->lineEditDaikuanzonge->text().toDouble();
                double benjin =  zonge;
                double meiyuebenjin = benjin/huankuanyueshu;
                double meiyuedijian = (benjin/huankuanyueshu * rate);
                double meiyuelixi = (benjin -benjin*(1-1)/huankuanyueshu)*rate;



                ui->zonge->setText(QString::number(zonge,'f',0));

                double money = meiyuebenjin+meiyuelixi;
                ui->yuegong->setText(QString::number(money,'f',0));
                ui->huankuanzonge->setText(QString::number(benjin+(huankuanyueshu+1)*benjin*rate/2,'f',0));
                //首付
                //ui->shoufu->setText(QString::number(zonge));
                ui->lixi->setText(QString::number((huankuanyueshu+1)*benjin*rate/2,'f',0));
                ui->meiyuedijian->setText(QString::number(meiyuedijian,'f',0));
            }
    }
    }
    //组合贷款
    else if(2 == m_mortType)
    {
        double shangdaizonge;
        double gongjijinzonge;
        double shangdairate;
        double gongjijinrate;
        if(""!=ui->lineEditshangdaiRate->text())
        {
            shangdairate = ui->lineEditshangdaiRate->text().toDouble()*0.01/12;
        }
        if(""!=ui->lineEditgongjijinRate->text())
        {
            gongjijinrate = ui->lineEditgongjijinRate->text().toDouble()*0.01/12;
        }
        if(""!=ui->lineEditshangyedaikuangzonge->text())
        {
            shangdaizonge = ui->lineEditshangyedaikuangzonge->text().toDouble();
        }
        if(""!=ui->lineEditgongjijindaikuanzonge->text())
        {
            gongjijinzonge = ui->lineEditgongjijindaikuanzonge->text().toDouble();
        }
        //等额本息
        if(m_repaymentTupe1)
        {
           // zonge = price * area;
            ui->zonge->setText(QString::number(shangdaizonge+gongjijinzonge));

            double money1 = shangdaizonge * (shangdairate* qPow(1+shangdairate,(25- m_numOfYear)*12))/(qPow(1+shangdairate,12*(25- m_numOfYear))-1);
            double money2 = gongjijinzonge * (gongjijinrate* qPow(1+gongjijinrate,(25- m_numOfYear)*12))/(qPow(1+gongjijinrate,12*(25- m_numOfYear))-1);
            ui->yuegong->setText(QString::number(money1+money2,'f',0));
            ui->huankuanzonge->setText(QString::number((money1+money2)*(25- m_numOfYear)*12,'f',0));

            ui->lixi->setText(QString::number((money1+money2)*(25- m_numOfYear)*12-(shangdaizonge+gongjijinzonge),'f',0));

        }
        //等额本金
        else if(m_repaymentTupe2)
        {

            double benjin =  shangdaizonge+gongjijinzonge;
            double meiyuebenjin = benjin/huankuanyueshu;
            double meiyuedijian = (shangdaizonge/huankuanyueshu*(shangdairate))+
                    (gongjijinzonge/huankuanyueshu*(gongjijinrate));
            double meiyuelixi = (shangdaizonge -shangdaizonge*(1-1)/huankuanyueshu)*(shangdairate)+
                    (gongjijinzonge -gongjijinzonge*(1-1)/huankuanyueshu)*(gongjijinrate);


            //zonge = price * area;
            ui->zonge->setText(QString::number(benjin,'f',0));

            double money = meiyuebenjin+meiyuelixi;
            ui->shouyuegong->setText(QString::number(money,'f',0));
            ui->huankuanzonge->setText(QString::number(shangdaizonge+(huankuanyueshu+1)*shangdaizonge*(shangdairate)/2 +
                                                       gongjijinzonge+(huankuanyueshu+1)*gongjijinzonge*(gongjijinrate)/2,'f',0));

            ui->lixi->setText(QString::number((huankuanyueshu+1)*shangdaizonge*(shangdairate)/2 +
                                              (huankuanyueshu+1)*gongjijinzonge*(gongjijinrate)/2,'f',0));
            ui->meiyuedijian->setText(QString::number(meiyuedijian,'f',0));



        }
    }
}
void Widget::pushButtonClear()
{
    ui->lineEditRate->clear();
    ui->lineEditarea->clear();
    ui->lineEditPrice->clear();
    ui->lineEditDaikuanzonge->clear();
    ui->lineEditshangdaiRate->clear();
    ui->lineEditgongjijinRate->clear();
    ui->lineEditshangyedaikuangzonge->clear();
    ui->lineEditgongjijindaikuanzonge->clear();
}
