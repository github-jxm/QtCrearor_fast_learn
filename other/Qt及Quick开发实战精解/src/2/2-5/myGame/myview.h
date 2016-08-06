#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
class BoxGroup;
// 在2-5中添加的代码
#include <phonon>

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = 0);

// 在2-4中添加的代码
protected:
    void keyPressEvent(QKeyEvent *event);

public slots:
    void startGame();
    void clearFullRows();
    void moveBox();
    void gameOver();

    // 在2-4中添加的代码
    void restartGame();
    void finishGame();
    void pauseGame();
    void returnGame();

    // 在2-5中添加的代码
    void aboutToFinish();

private:
    BoxGroup *boxGroup;
    BoxGroup *nextBoxGroup;
    QGraphicsLineItem *topLine;
    QGraphicsLineItem *bottomLine;
    QGraphicsLineItem *leftLine;
    QGraphicsLineItem *rightLine;
    qreal gameSpeed;
    QList<int> rows;
    void initView();
    void initGame();
    void updateScore(const int fullRowNum = 0);

    // 在2-3中添加的代码
    QGraphicsTextItem *gameScoreText;
    QGraphicsTextItem *gameLevelText;

    // 在2-4中添加的代码

    // 遮罩面板
    QGraphicsWidget *maskWidget;

    // 各种按钮
    QGraphicsWidget *startButton;
    QGraphicsWidget *finishButton;
    QGraphicsWidget *restartButton;
    QGraphicsWidget *pauseButton;
    QGraphicsWidget *optionButton;
    QGraphicsWidget *returnButton;
    QGraphicsWidget *helpButton;
    QGraphicsWidget *exitButton;
    QGraphicsWidget *showMenuButton;

    // 各种文本
    QGraphicsTextItem *gameWelcomeText;
    QGraphicsTextItem *gamePausedText;
    QGraphicsTextItem *gameOverText;

    // 在2-5中添加的代码
    Phonon::MediaObject *backgroundMusic;
    Phonon::MediaObject *clearRowSound;
};

#endif // MYVIEW_H
