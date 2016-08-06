#include "myview.h"
#include "mybox.h"
#include <QIcon>

// 在2-2中添加的代码
#include <QPropertyAnimation>
#include <QGraphicsBlurEffect>
#include <QTimer>

// 游戏的初始速度
static const qreal INITSPEED = 500;

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{
    initView();
}

// 初始化游戏界面
void MyView::initView()
{
    // 使用抗锯齿渲染
    setRenderHint(QPainter::Antialiasing);
    // 设置缓存背景，这样可以加快渲染速度
    setCacheMode(CacheBackground);
    setWindowTitle(tr("MyBox方块游戏"));
    setWindowIcon(QIcon(":/images/icon.png"));
    setMinimumSize(810, 510);
    setMaximumSize(810, 510);

    // 设置场景
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(5, 5, 800, 500);
    scene->setBackgroundBrush(QPixmap(":/images/background.png"));
    setScene(scene);

    // 方块可移动区域的四条边界线
    topLine = scene->addLine(197, 47, 403, 47);
    bottomLine = scene->addLine(197,453,403,453);
    leftLine = scene->addLine(197,47,197,453);
    rightLine = scene->addLine(403,47,403,453);


    // 当前方块组和提示方块组
    boxGroup = new BoxGroup;
    connect(boxGroup, SIGNAL(needNewBox()), this, SLOT(clearFullRows()));
    connect(boxGroup, SIGNAL(gameFinished()), this, SLOT(gameOver()));
    scene->addItem(boxGroup);
    nextBoxGroup = new BoxGroup;
    scene->addItem(nextBoxGroup);

    startGame();
}

// 开始游戏
void MyView::startGame()
{
    initGame();
}

// 初始化游戏
void MyView::initGame()
{
    boxGroup->createBox(QPointF(300, 70));
    boxGroup->setFocus();
    boxGroup->startTimer(INITSPEED);
    gameSpeed = INITSPEED;
    nextBoxGroup->createBox(QPointF(500, 70));
}

// 清空满行
void MyView::clearFullRows()
{
    // 获取比一行方格较大的矩形中包含的所有小方块
    for (int y = 429; y > 50; y -= 20) {
        QList<QGraphicsItem *> list = scene()->items(199, y, 202, 22, Qt::ContainsItemShape);
        // 如果该行已满
        if (list.count() == 10) {
            foreach (QGraphicsItem *item, list) {
                OneBox *box = (OneBox*) item;

                // 在2-2中添加的代码
                QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
                box->setGraphicsEffect(blurEffect);
                QPropertyAnimation *animation = new QPropertyAnimation(box, "scale");
                animation->setEasingCurve(QEasingCurve::OutBounce);
                animation->setDuration(250);
                animation->setStartValue(4);
                animation->setEndValue(0.25);
                animation->start(QAbstractAnimation::DeleteWhenStopped);
                connect(animation, SIGNAL(finished()), box, SLOT(deleteLater()));
            }
            // 保存满行的位置
            rows << y;
        }
    }
    // 如果有满行，下移满行上面的各行再出现新的方块组
    // 如果没有满行，则直接出现新的方块组
    if(rows.count() > 0) {

        // 在2-2中添加的代码
        QTimer::singleShot(400, this, SLOT(moveBox()));

    } else {
        boxGroup->createBox(QPointF(300, 70), nextBoxGroup->getCurrentShape());
        // 清空并销毁提示方块组中的所有小方块
        nextBoxGroup->clearBoxGroup(true);
        nextBoxGroup->createBox(QPointF(500, 70));
    }
}

// 下移满行上面的所有小方块
void MyView::moveBox()
{
    // 从位置最靠上的满行开始
    for (int i = rows.count(); i > 0;  --i) {
        int row = rows.at(i - 1);
        foreach (QGraphicsItem *item, scene()->items(199, 49, 202, row - 47, Qt::ContainsItemShape)) {
            item->moveBy(0, 20);
        }
    }
    // 更新分数
    updateScore(rows.count());
    // 将满行列表清空为0
    rows.clear();
    // 等所有行下移以后再出现新的方块组
    boxGroup->createBox(QPointF(300, 70), nextBoxGroup->getCurrentShape());
    nextBoxGroup->clearBoxGroup(true);
    nextBoxGroup->createBox(QPointF(500, 70));
}


void MyView::updateScore(const int fullRowNum)
{
    // 更新分数
}

void MyView::gameOver()
{
    // 游戏结束
}






