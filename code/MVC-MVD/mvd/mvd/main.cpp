#include "widget.h"
#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <QListView>
#include <QDebug>

#include <QStandardItemModel>

#include "stringlistmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFileSystemModel model;
//    model.setRootPath(QDir::currentPath());

//    QTreeView tree;
//    tree.setModel(&model);
//    tree.setRootIndex(model.index(QDir::currentPath()));

//    QListView list;
//    list.setModel(&model);
//    list.setRootIndex(model.index(QDir::currentPath()));

//    tree.show();
//    list.show();



//    QStandardItemModel model;
//    QStandardItem *parentItem = model.invisibleRootItem();
//    QStandardItem *item0 = new QStandardItem;
//    item0->setText("A");
//    QPixmap pixmap0(50, 50);
//    pixmap0.fill("red");
//    item0->setIcon(QIcon(pixmap0));
//    item0->setToolTip("indexA");
//    parentItem->appendRow(item0);
//    parentItem = item0;

//    QStandardItem *item1 = new QStandardItem;
//    item1->setText("B");
//    QPixmap pixmap1(50, 50);
//    pixmap1.fill("blue");
//    item1->setIcon(QIcon(pixmap1));
//    item1->setToolTip("indexB");
//    parentItem->appendRow(item1);

//    QStandardItem *item2= new QStandardItem;
//    QPixmap pixmap2(50, 50);
//    pixmap2.fill("green");
//    item2->setData("C", Qt::EditRole);
//    item2->setData("INdexC", Qt::ToolTipRole);
//    item2->setData(QIcon(pixmap2), Qt::DecorationRole);
//    parentItem->appendRow(item2);

//    QTreeView view;
//    view.setModel(&model);
//    view.show();

//    QModelIndex indexA = model.index(0, 0, QModelIndex());
//    qDebug() << "indexA row count:" << model.rowCount(indexA);

//    QModelIndex indexB = model.index(0, 0, indexA);
//    qDebug() << "indexB text:" << model.data(indexB, Qt::EditRole).toString();
//    qDebug() << "indexB toolTip:" << model.data(indexB, Qt::ToolTipRole).toString();


//    QStringList list;
//    list << "a" << "b" <<"c" ;

//    StringListModel model(list);
//    QListView listView;
//    listView.setModel(&model);
//    listView.show();
//    QTableView tableView;
//    tableView.setModel(&model);
//    tableView.show();

//    model.insertRows(3, 2);
//    model.removeRows(0,1);





    Widget w;
    w.show();

    return a.exec();
}
