#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StringListModel(const QStringList &strings, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex())const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());


signals:

public slots:

private:
    QStringList stringList;
};

#endif // STRINGLISTMODEL_H
