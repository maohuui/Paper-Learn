#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTableView;
class QItemSelection;
class QModelIndex;

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void updateSelection(const QItemSelection &selected, const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::Widget *ui;

    QTableView *tableView;
    QTableView *tableView2;
};

#endif // WIDGET_H
