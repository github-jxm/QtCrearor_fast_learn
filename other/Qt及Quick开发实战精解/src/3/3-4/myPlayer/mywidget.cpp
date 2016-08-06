#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QToolBar>
#include <QVBoxLayout>
#include <QTime>
#include <QMessageBox>
#include <QFileInfo>
// 在3-3中添加的代码
#include "myplaylist.h"
#include <QFileDialog>
#include <QDesktopServices>

// 在3-4中添加的代码
#include "mylrc.h"
#include <QTextCodec>

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

    // 在3-2中添加的代码
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State, Phonon::State)),
            this, SLOT(stateChanged(Phonon::State, Phonon::State)));

    // 以下是在3-3中添加的代码

    // 创建播放列表
    playlist = new MyPlaylist(this);
    connect(playlist, SIGNAL(cellClicked(int, int)), this, SLOT(tableClicked(int)));
    connect(playlist, SIGNAL(playlistClean()), this, SLOT(clearSources()));

    // 创建用来解析媒体的信息的元信息解析器
    metaInformationResolver = new Phonon::MediaObject(this);
    // 需要与AudioOutput连接后才能使用metaInformationResolver来获取歌曲的总时间
    Phonon::AudioOutput *metaInformationAudioOutput =
            new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(metaInformationResolver, metaInformationAudioOutput);
    connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State, Phonon::State)),
            this, SLOT(metaStateChanged(Phonon::State, Phonon::State)));

    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));

    // 初始化动作图标的状态
    playAction->setEnabled(false);
    stopAction->setEnabled(false);
    skipBackwardAction->setEnabled(false);
    skipForwardAction->setEnabled(false);
    topLabel->setFocus();

    // 以下代码在3-4中添加
    // 创建歌词部件
    lrc = new MyLrc(this);

}

// 更新timeLabel标签显示的播放时间
void MyWidget::updateTime(qint64 time)
{
    qint64 totalTimeValue = mediaObject->totalTime();
    QTime totalTime(0, (totalTimeValue / 60000) % 60, (totalTimeValue / 1000) % 60);
    QTime currentTime(0, (time / 60000) % 60, (time / 1000) % 60);
    QString str = currentTime.toString("mm:ss") + " / " + totalTime.toString("mm:ss");
    timeLabel->setText(str);

    // 获取当期时间对应的歌词
    if(!lrcMap.isEmpty()) {
        // 获取当前时间在歌词中的前后两个时间点
        qint64 previous = 0;
        qint64 later = 0;
        foreach (qint64 value, lrcMap.keys()) {
            if (time >= value) {
                previous = value;
            } else {
                later = value;
                break;
            }
        }

        // 达到最后一行,将later设置为歌曲总时间的值
        if (later == 0)
            later = totalTimeValue;

        // 获取当前时间所对应的歌词内容
        QString currentLrc = lrcMap.value(previous);

        // 没有内容时
        if(currentLrc.length() < 2)
            currentLrc = tr("MyPlayer音乐播放器 --- yafeilinux作品");

        // 如果是新的一行歌词，那么重新开始显示歌词遮罩
        if(currentLrc != lrc->text()) {
            lrc->setText(currentLrc);
            topLabel->setText(currentLrc);
            qint64 intervalTime = later - previous;
            lrc->startLrcMask(intervalTime);
        }
    } else {  // 如果没有歌词文件，则在顶部标签中显示歌曲标题
        topLabel->setText(QFileInfo(mediaObject->
                                    currentSource().fileName()).baseName());
    }
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
    lrc->stopLrcMask();
    int index = sources.indexOf(mediaObject->currentSource());
    mediaObject->setCurrentSource(sources.at(index - 1));
    mediaObject->play();
}

// 播放下一首，与skipForwardAction动作的触发信号关联
void MyWidget::skipForward()
{
    lrc->stopLrcMask();
    int index = sources.indexOf(mediaObject->currentSource());
    mediaObject->setCurrentSource(sources.at(index + 1));
    mediaObject->play();
}

// 打开文件，与openAction动作的触发信号关联
void MyWidget::openFile()
{
    // 从系统音乐目录打开多个音乐文件
    QStringList list = QFileDialog::getOpenFileNames(this, tr("打开音乐文件"),
                      QDesktopServices::storageLocation(QDesktopServices::MusicLocation));
    if (list.isEmpty())
        return;
    // 获取当前媒体源列表的大小
    int index = sources.size();
    // 将打开的音乐文件添加到媒体源列表后
    foreach (QString string, list) {
        Phonon::MediaSource source(string);
        sources.append(source);
    }
    // 如果媒体源列表不为空，则将新加入的第一个媒体源作为当前媒体源，
    // 这时会发射stateChanged()信号，从而调用metaStateChanged()函数进行媒体源的解析
    if (!sources.isEmpty())
        metaInformationResolver->setCurrentSource(sources.at(index));
}

// 显示或者隐藏播放列表，与PLAction动作的触发信号关联
void MyWidget::setPlaylistShown()
{
    if (playlist->isHidden()) {
        playlist->move(frameGeometry().bottomLeft());
        playlist->show();
    } else {
        playlist->hide();
    }
}

// 显示或者隐藏桌面歌词，与LRCAction动作的触发信号关联
void MyWidget::setLrcShown()
{   
    if (lrc->isHidden())
        lrc->show();
    else
        lrc->hide();
}

// 媒体对象状态发生了改变
void MyWidget::stateChanged(Phonon::State newState, Phonon::State oldState)
{
    switch (newState)
    {
    case Phonon::ErrorState :
        if(mediaObject->errorType() == Phonon::FatalError) {
            QMessageBox::warning(this, tr("致命错误"),
                                 mediaObject->errorString());
        } else {
            QMessageBox::warning(this, tr("错误"), mediaObject->errorString());
        }
        break;
    case Phonon::PlayingState :
        stopAction->setEnabled(true);
        playAction->setIcon(QIcon(":/images/pause.png"));
        playAction->setText(tr("暂停(F5)"));
        topLabel->setText(QFileInfo(mediaObject->
                                    currentSource().fileName()).baseName());
        //解析当前媒体源对应的歌词文件
        resolveLrc(mediaObject->currentSource().fileName());
        break;
    case Phonon::StoppedState :
        stopAction->setEnabled(false);
        playAction->setIcon(QIcon(":/images/play.png"));
        playAction->setText(tr("播放(F5)"));
        topLabel->setText(tr("<a href = \" http://www.yafeilinux.com \">"
                             "www.yafeilinux.com</a>"));
        timeLabel->setText(tr("00:00 / 00:00"));
        // 停止歌词遮罩
        lrc->stopLrcMask();
        lrc->setText(tr("MyPlayer音乐播放器 --- yafeilinux作品"));
        break;
    case Phonon::PausedState :
        stopAction->setEnabled(true);
        playAction->setIcon(QIcon(":/images/play.png"));
        playAction->setText(tr("播放(F5)"));
        topLabel->setText(QFileInfo(mediaObject->
                                    currentSource().fileName()).baseName() + tr(" 已暂停！"));
        // 如果该歌曲有歌词文件
        if (!lrcMap.isEmpty()) {
            lrc->stopLrcMask();
            lrc->setText(topLabel->text());
        }
        break;
    case Phonon::BufferingState :
        break;
    default :
        ;
    }
}

// 解析媒体文件的元信息
void MyWidget::metaStateChanged(Phonon::State newState, Phonon::State oldState)
{
    // 错误状态，则从媒体源列表中除去新添加的媒体源
    if(newState == Phonon::ErrorState) {
        QMessageBox::warning(this, tr("打开文件时出错"), metaInformationResolver->errorString());
        while (!sources.isEmpty() &&
               !(sources.takeLast() == metaInformationResolver->currentSource()))
        {};
        return;
    }

    // 如果既不处于停止状态也不处于暂停状态，则直接返回
    if(newState != Phonon::StoppedState && newState != Phonon::PausedState)
        return;

    // 如果媒体源类型错误，则直接返回
    if(metaInformationResolver->currentSource().type() == Phonon::MediaSource::Invalid)
        return;

    // 获取媒体信息
    QMap<QString, QString> metaData = metaInformationResolver->metaData();
    // 获取标题，如果为空，则使用文件名
    QString title = metaData.value("TITLE");
    if (title == "") {
        QString str = metaInformationResolver->currentSource().fileName();
        title = QFileInfo(str).baseName();
    }
    QTableWidgetItem *titleItem = new QTableWidgetItem(title);
    // 设置数据项不可编辑
    titleItem->setFlags(titleItem->flags() ^ Qt::ItemIsEditable);
    // 获取艺术家信息
    QTableWidgetItem *artistItem = new QTableWidgetItem(metaData.value("ARTIST"));
    artistItem->setFlags(artistItem->flags() ^ Qt::ItemIsEditable);
    // 获取总时间信息
    qint64 totalTime = metaInformationResolver->totalTime();
    QTime time(0, (totalTime / 60000) % 60, (totalTime / 1000) % 60);
    QTableWidgetItem *timeItem = new QTableWidgetItem(time.toString("mm:ss"));

    // 插入到播放列表
    int currentRow = playlist->rowCount();
    playlist->insertRow(currentRow);
    playlist->setItem(currentRow, 0, titleItem);
    playlist->setItem(currentRow, 1, artistItem);
    playlist->setItem(currentRow, 2, timeItem);

    // 如果添加的媒体源还没有解析完，那么继续解析下一个媒体源
    int index = sources.indexOf(metaInformationResolver->currentSource()) + 1;
    if (sources.size() > index) {
        metaInformationResolver->setCurrentSource(sources.at(index));
    } else { // 如果所有媒体源都已经解析完成
        // 如果播放列表中没有选中的行
        if (playlist->selectedItems().isEmpty()) {
            // 如果现在没有播放歌曲则设置第一个媒体源为媒体对象的当前媒体源
            //（因为可能正在播放歌曲时清空了播放列表，然后又添加了新的列表）
            if (mediaObject->state() != Phonon::PlayingState &&
                    mediaObject->state() != Phonon::PausedState) {
                mediaObject->setCurrentSource(sources.at(0));
            } else {
                //如果正在播放歌曲，则选中播放列表的第一个曲目,并更改图标状态
                playlist->selectRow(0);
                changeActionState();
            }
        } else {
            // 如果播放列表中有选中的行，那么直接更新图标状态
            changeActionState();
        }
    }
}

// 根据媒体源列表内容和当前媒体源的位置来改变主界面图标的状态
void MyWidget::changeActionState()
{
    // 如果媒体源列表为空
    if (sources.count() == 0) {
        // 如果没有在播放歌曲，则播放和停止按钮都不可用
        //（因为可能歌曲正在播放时清除了播放列表）
        if (mediaObject->state() != Phonon::PlayingState &&
                mediaObject->state() != Phonon::PausedState) {
            playAction->setEnabled(false);
            stopAction->setEnabled(false);
        }
        skipBackwardAction->setEnabled(false);
        skipForwardAction->setEnabled(false);
    } else { // 如果媒体源列表不为空
        playAction->setEnabled(true);
        stopAction->setEnabled(true);
        // 如果媒体源列表只有一行
        if (sources.count() == 1) {
            skipBackwardAction->setEnabled(false);
            skipForwardAction->setEnabled(false);
        } else { // 如果媒体源列表有多行
            skipBackwardAction->setEnabled(true);
            skipForwardAction->setEnabled(true);
            int index = playlist->currentRow();
            // 如果播放列表当前选中的行为第一行
            if (index == 0)
                skipBackwardAction->setEnabled(false);
            // 如果播放列表当前选中的行为最后一行
            if (index + 1 == sources.count())
                skipForwardAction->setEnabled(false);
        }
    }
}

// 当媒体源改变时，在播放列表中选中相应的行并更新图标的状态
void MyWidget::sourceChanged(const Phonon::MediaSource &source)
{
    int index = sources.indexOf(source);
    playlist->selectRow(index);
    changeActionState();
}

// 当前媒体源播放将要结束时，如果在列表中当前媒体源的后面还有媒体源，
// 那么将它添加到播放队列中，否则停止播放
void MyWidget::aboutToFinish()
{
    int index = sources.indexOf(mediaObject->currentSource()) + 1;
    if (sources.size() > index) {
        mediaObject->enqueue(sources.at(index));
        // 跳转到歌曲最后
        mediaObject->seek(mediaObject->totalTime());
        // 停止歌词遮罩并重新解析歌词
        lrc->stopLrcMask();
        resolveLrc(sources.at(index).fileName());
    } else {
        mediaObject->stop();
    }
}

// 单击播放列表
void MyWidget::tableClicked(int row)
{
    // 首先获取媒体对象当前的状态，然后停止播放并清空播放队列
    bool wasPlaying = mediaObject->state() == Phonon::PlayingState;
    mediaObject->stop();
    mediaObject->clearQueue();

    // 如果单击的播放列表中的行号大于媒体源列表的大小，则直接返回
    if(row >= sources.size())
        return;
    // 设置单击的行对应的媒体源为媒体对象的当前媒体源
    mediaObject->setCurrentSource(sources.at(row));
    // 如果以前媒体对象处于播放状态，那么开始播放选中的曲目
    if (wasPlaying)
        mediaObject->play();
}

// 清空媒体源列表，它与播放列表的playListClean()信号关联
void MyWidget::clearSources()
{
    sources.clear();
    // 更改动作图标状态
    changeActionState();
}

// 解析LRC歌词，在stateChanged()函数的Phonon::PlayingState处和aboutToFinish()函数中调用了该函数
void MyWidget::resolveLrc(const QString &sourceFileName)
{
    // 先清空以前的内容
    lrcMap.clear();

    // 获取LRC歌词的文件名
    if(sourceFileName.isEmpty())
        return ;
    QString fileName = sourceFileName;
    QString lrcFileName = fileName.remove(fileName.right(3)) + "lrc";

    // 打开歌词文件
    QFile file(lrcFileName);
    if (!file.open(QIODevice::ReadOnly)) {
        lrc->setText(QFileInfo(mediaObject->currentSource().fileName()).baseName()
                     + tr(" --- 未找到歌词文件！"));
        return ;
    }
    // 设置字符串编码
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    // 获取全部歌词信息
    QString allText = QString(file.readAll());
    // 关闭歌词文件
    file.close();
    // 将歌词按行分解为歌词列表
    QStringList lines = allText.split("\n");

    // 使用正则表达式将时间标签和歌词内容分离
    QRegExp rx("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");
    foreach (QString oneLine, lines) {
        // 先在当前行的歌词的备份中将时间内容清除，这样就获得了歌词文本
        QString temp = oneLine;
        temp.replace(rx, "");
        // 然后依次获取当前行中的所有时间标签，并分别与歌词文本存入QMap中
        int pos = rx.indexIn(oneLine, 0);
        while (pos != -1) {
            QString cap = rx.cap(0);
            // 将时间标签转换为时间数值，以毫秒为单位
            QRegExp regexp;
            regexp.setPattern("\\d{2}(?=:)");
            regexp.indexIn(cap);
            int minute = regexp.cap(0).toInt();
            regexp.setPattern("\\d{2}(?=\\.)");
            regexp.indexIn(cap);
            int second = regexp.cap(0).toInt();
            regexp.setPattern("\\d{2}(?=\\])");
            regexp.indexIn(cap);
            int millisecond = regexp.cap(0).toInt();
            qint64 totalTime = minute * 60000 + second * 1000 + millisecond * 10;
            // 插入到lrcMap中
            lrcMap.insert(totalTime, temp);
            pos += rx.matchedLength();
            pos = rx.indexIn(oneLine, pos);
        }
    }
    // 如果lrcMap为空
    if (lrcMap.isEmpty()) {
        lrc->setText(QFileInfo(mediaObject->currentSource().fileName()).baseName()
                     + tr(" --- 歌词文件内容错误！"));
        return;
    }
}

