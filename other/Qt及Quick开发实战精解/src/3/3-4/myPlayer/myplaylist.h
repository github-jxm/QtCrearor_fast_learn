#ifndef MYPLAYLIST_H
#define MYPLAYLIST_H

#include <QTableWidget>

class MyPlaylist : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyPlaylist(QWidget *parent = 0);

protected:
    void contextMenuEvent(QContextMenuEvent *event);
    void closeEvent(QCloseEvent *event);

signals:
    void playlistClean();

private slots:
    void clearPlaylist();
};

#endif // MYPLAYLIST_H
