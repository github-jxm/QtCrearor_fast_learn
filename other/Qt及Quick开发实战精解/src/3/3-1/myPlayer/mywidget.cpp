#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QToolBar>
#include <QVBoxLayout>
#include <QTime>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    initPlayer();
}

MyWidget::~MyWidget()
{
    delete ui;
}

// 初始化播放器
void MyWidget::initPlayer()
{
    // 设置主界面标题、图标和大小
    setWindowTitle(tr("MyPlayer音乐播放器"));
    setWindowIcon(QIcon(":/images/icon.png"));
    setMinimumSize(320, 160);
    setMaximumSize(320, 160);

    // 创建媒体图
    mediaObject = new Phonon::MediaObject(this);
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObject, audioOutput);

    // 关联媒体对象的tick()信号来更新播放时间的显示
    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(updateTime(qint64)));

    // 创建顶部标签，用于显示一些信息
    topLabel = new QLabel(tr("<a href = \" http://www.yafeilinux.com \"> www.yafeilinux.com </a>"));
    topLabel->setTextFormat(Qt::RichText);
    topLabel->setOpenExternalLinks(true);
    topLabel->setAlignment(Qt::AlignCenter);

    // 创建控制播放进度的滑块
    Phonon::SeekSlider *seekSlider = new Phonon::SeekSlider(mediaObject, this);

    // 创建包含播放列表图标、显示时间标签和桌面歌词图标的工具栏
    QToolBar *widgetBar = new QToolBar(this);
    // 显示播放时间的标签
    timeLabel = new QLabel(tr("00:00 / 00:00"), this);
    timeLabel->setToolTip(tr("当前时间 / 总时间"));
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    // 创建图标，用于控制是否显示播放列表
    QAction *PLAction = new QAction(tr("PL"), this);
    PLAction->setShortcut(QKeySequence("F4"));
    PLAction->setToolTip(tr("播放列表(F4)"));
    connect(PLAction, SIGNAL(triggered()), this, SLOT(setPlaylistShown()));
    // 创建图标，用于控制是否显示桌面歌词
    QAction *LRCAction = new QAction(tr("LRC"), this);
    LRCAction->setShortcut(QKeySequence("F2"));
    LRCAction->setToolTip(tr("桌面歌词(F2)"));
    connect(LRCAction, SIGNAL(triggered()), this, SLOT(setLrcShown()));
    // 添加到工具栏
    widgetBar->addAction(PLAction);
    widgetBar->addSeparator();
    widgetBar->addWidget(timeLabel);
    widgetBar->addSeparator();
    widgetBar->addAction(LRCAction);

    // 创建播放控制动作工具栏
    QToolBar *toolBar = new QToolBar(this);
    // 播放动作
    playAction = new QAction(this);
    playAction->setIcon(QIcon(":/images/play.png"));
    playAction->setText(tr("播放(F5)"));
    playAction->setShortcut(QKeySequence(tr("F5")));
    connect(playAction, SIGNAL(triggered()), this, SLOT(setPaused()));
    // 停止动作
    stopAction = new QAction(this);
    stopAction->setIcon(QIcon(":/images/stop.png"));
    stopAction->setText(tr("停止(F6)"));
    stopAction->setShortcut(QKeySequence(tr("F6")));
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));
    // 跳转到上一首动作
    skipBackwardAction = new QAction(this);
    skipBackwardAction->setIcon(QIcon(":/images/skipBackward.png"));
    skipBackwardAction->setText(tr("上一首(Ctrl+Left)"));
    skipBackwardAction->setShortcut(QKeySequence(tr("Ctrl+Left")));
    connect(skipBackwardAction, SIGNAL(triggered()), this, SLOT(skipBackward()));
    // 跳转到下一首动作
    skipForwardAction = new QAction(this);
    skipForwardAction->setIcon(QIcon(":/images/skipForward.png"));
    skipForwardAction->setText(tr("下一首(Ctrl+Right)"));
    skipForwardAction->setShortcut(QKeySequence(tr("Ctrl+Right")));
    connect(skipForwardAction, SIGNAL(triggered()), this, SLOT(skipForward()));
    // 打开文件动作
    QAction *openAction = new QAction(this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setText(tr("播放文件(Ctrl+O)"));
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    // 音量控制部件
    Phonon::VolumeSlider *volumeSlider = new Phonon::VolumeSlider(audioOutput, this);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    // 添加到工具栏
    toolBar->addAction(playAction);
    toolBar->addSeparator();
    toolBar->addAction(stopAction);
    toolBar->addSeparator();
    toolBar->addAction(skipBackwardAction);
    toolBar->addSeparator();
    toolBar->addAction(skipForwardAction);
    toolBar->addSeparator();
    toolBar->addWidget(volumeSlider);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    // 创建主界面布局管理器
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(topLabel);
    mainLayout->addWidget(seekSlider);
    mainLayout->addWidget(widgetBar);
    mainLayout->addWidget(toolBar);
    setLayout(mainLayout);

    mediaObject->setCurrentSource(Phonon::MediaSource("../myPlayer/music.mp3"));
}

// 更新timeLabel标签显示的播放时间
void MyWidget::updateTime(qint64 time)
{
    qint64 totalTimeValue = mediaObject->totalTime();
    QTime totalTime(0, (totalTimeValue / 60000) % 60, (totalTimeValue / 1000) % 60);
    QTime currentTime(0, (time / 60000) % 60, (time / 1000) % 60);
    QString str = currentTime.toString("mm:ss") + " / " + totalTime.toString("mm:ss");
    timeLabel->setText(str);
}

// 播放或者暂停
void MyWidget::setPaused()
{
    // 如果先前处于播放状态，那么暂停播放;否则，开始播放
    if (mediaObject->state() == Phonon::PlayingState)
        mediaObject->pause();
    else
        mediaObject->play();
}

// 播放上一首，与skipBackwardAction动作的触发信号关联
void MyWidget::skipBackward()
{
}

// 播放下一首，与skipForwardAction动作的触发信号关联
void MyWidget::skipForward()
{
}

// 打开文件，与openAction动作的触发信号关联
void MyWidget::openFile()
{
}

// 显示或者隐藏播放列表，与PLAction动作的触发信号关联
void MyWidget::setPlaylistShown()
{
}

// 显示或者隐藏桌面歌词，与LRCAction动作的触发信号关联
void MyWidget::setLrcShown()
{
}
