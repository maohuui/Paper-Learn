#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>
#include <QHBoxLayout>
#include "spinboxdelegate.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(7, 4, this);
    for(int row = 0; row<7; ++row) {
        for(int column = 0; column<4; ++column) {
            QStandardItem *item = new QStandardItem(QString("%1").arg(row *4+column));
            model->setItem(row, column, item);
        }
    }
    tableView = new QTableView;
    tableView->setModel(model);

    QHBoxLayout *layout  = new QHBoxLayout;
    layout->addWidget(tableView);
    ui->widget->setLayout(layout);

    QItemSelectionModel *selectionModel = tableView->selectionModel();
    QModelIndex topLeft;
    QModelIndex bottomRight;
    topLeft = model->index(1,1, QModelIndex());
    bottomRight = model->index(5, 2, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &Widget::updateSelection);
    connect(selectionModel, &QItemSelectionModel::currentChanged, this, &Widget::changeCurrent);

    tableView2 = new QTableView;
    tableView2->setWindowTitle("2");
    tableView2->resize(400,300);
    tableView2->setModel(model);
    tableView2->setSelectionModel(selectionModel);
    tableView2->show();

    SpinBoxDelegate *delegate = new SpinBoxDelegate(this);
    tableView->setItemDelegate(delegate);

    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    tableView->setDragEnabled(true);
    tableView->setAcceptDrops(true);
    tableView->setDropIndicatorShown(true);
}

Widget::~Widget()
{
    delete ui;
    delete tableView2;
}

void Widget::on_pushButton_clicked()
{
    qDebug() << tr("current:") <<tableView->selectionModel()->currentIndex().data().toString();
}

void Widget::on_pushButton_2_clicked()//反选
{
    QModelIndex topLeft = tableView->model()->index(0, 0, QModelIndex());
    QModelIndex bottomRight = tableView->model()->index( tableView->model()->rowCount(QModelIndex())-1, tableView->model()->columnCount(QModelIndex())-1, QModelIndex());
    QItemSelection curSelection(topLeft, bottomRight);
    tableView->selectionModel()->select(curSelection, QItemSelectionModel::Toggle);
}

void Widget::updateSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index;
    QModelIndexList list = selected.indexes();
    foreach (index, list) {
        QString text = QString("(%1, %2)").arg(index.row()).arg(index.column());
        tableView->model()->setData(index, text);
    }
    list = deselected.indexes();
    foreach (index, list) {
        tableView->model()->setData(index, "");
    }
}

void Widget::changeCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug() << tr("move(%1, %2) to (%3, %4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}
