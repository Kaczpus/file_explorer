#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDirModel>
#include <QInputDialog>
namespace Ui {
class File_explorer;
}

class File_explorer : public QDialog
{
    Q_OBJECT

public:
    explicit File_explorer(QWidget *parent = 0);
    ~File_explorer();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::File_explorer *ui;
   QDirModel *model;
};

#endif // FILE_EXPLORER_H
