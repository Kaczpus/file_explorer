#include "file_explorer.h"
#include "ui_file_explorer.h"

File_explorer::File_explorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File_explorer)
{
    ui->setupUi(this);

    model = new QDirModel(this);
    model->setReadOnly(false);
    ui->treeView->setModel(model);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    QModelIndex index = model->index("/home/kaczpus");

    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->resizeColumnToContents(0);
}

File_explorer::~File_explorer()
{
    delete ui;
}

void File_explorer::on_pushButton_2_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid())
        return;
    QString name = QInputDialog::getText(this,"A","enter name");

   if(name.isEmpty())
       return;
   model->mkdir(index,name);
}

void File_explorer::on_pushButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid())
        return;
    if(model->fileInfo(index).isDir())
    {
        model->rmdir((index));
    }
    else
    {
        model->remove(index);
    }
}
