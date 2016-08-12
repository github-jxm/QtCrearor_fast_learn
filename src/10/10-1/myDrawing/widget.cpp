#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    /* 1. 绘制线条 */
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    /* 创建画笔 */
                     /*   画刷 线宽 画笔风格      画笔端点风格   画笔连接风格 */
    QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);

    //使用画笔
    painter.setPen(pen);
    QRectF rectangle(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30 * 16;  /* 实际角度值 x 16*/
    int spanAngle = 120 * 16;

    /* 2. 绘制圆弧 */
    painter.drawArc(rectangle, startAngle, spanAngle);

    //重新设置画笔
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    /* 3. 绘制一个矩形 */
    painter.drawRect(160, 20, 50, 40);

    //重新设置画笔
    pen.setColor(QColor(255,0,0));
    painter.setPen(pen);
    //创建画刷
    QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);
    //使用画刷
    painter.setBrush(brush);
    /* 4. 绘制椭圆 */
    painter.drawEllipse(220, 20, 60, 40);

    //设置纹理
    brush.setTexture(QPixmap("../myDrawing/yafeilinux.png"));
    //重新使用画刷
    painter.setBrush(brush);
    //定义四个点
    static const QPointF points[4] = {
        QPointF(270.0, 80.0),
        QPointF(290.0, 10.0),
        QPointF(350.0, 30.0),
        QPointF(390.0, 70.0)
    };
    /* 5. 使用四个点绘制多边形 */
    painter.drawPolygon(points, 4);

    /* 6 使用画刷填充一个矩形区域 */
    painter.fillRect(QRect(10, 100, 150, 20), QBrush(Qt::darkYellow));
    //擦除一个矩形区域的内容
    painter.eraseRect(QRect(50, 0, 50, 120));

    /*线性渐变*/
    QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190)); // 线性渐变
    /*插入颜色*/
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    /*指定渐变区域以外的区域的扩散方式*/
    linearGradient.setSpread(QGradient::RepeatSpread);  // 重复渐变
    // linearGradient.setSpread(QGradient::PadSpread);   // 使用最近使用的颜色进行填充  默认值
    // linearGradient.setSpread(QGradient::ReflectSpread); // 反射渐变
    /*使用渐变作为画刷*/
    painter.setBrush(linearGradient);
    /* 7 绘制线性渐变*/
    painter.drawRect(10, 170, 90, 40);

    /* 8 辐射渐变*/
    QRadialGradient radialGradient(QPointF(200, 190), 50, QPointF(275, 200));
    radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
    radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
    painter.setBrush(radialGradient);
    painter.drawEllipse(QPointF(200, 190), 50, 50);

    /* 9 锥形渐变 */
    QConicalGradient conicalGradient(QPointF(350, 190), 60);
    conicalGradient.setColorAt(0.2, Qt::cyan);
    conicalGradient.setColorAt(0.5, Qt::blue);
    conicalGradient.setColorAt(0.9, Qt::black);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(350, 190), 50, 50);

    /* 10 画笔使用线性渐变来绘制直线和文字 */
    painter.setPen(QPen(linearGradient,2));
    painter.drawLine(0, 280, 100, 280);
    painter.drawText(150, 280,  tr("helloQt!"));
}
