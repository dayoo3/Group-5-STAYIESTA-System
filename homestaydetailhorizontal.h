#ifndef HomestayDetailHorizontal_H
#define HomestayDetailHorizontal_H

#include "QAbstractProxyModel"

class HomestayDetailHorizontal : public QAbstractProxyModel {
public:
  HomestayDetailHorizontal(QObject* parent = nullptr);
  QModelIndex mapToSource(const QModelIndex &proxyIndex) const;
  QModelIndex mapFromSource(const QModelIndex &sourceIndex) const;
  QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
  QModelIndex parent(const QModelIndex &child) const;
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

HomestayDetailHorizontal::HomestayDetailHorizontal(QObject *parent) :
  QAbstractProxyModel(parent) {
}

QModelIndex HomestayDetailHorizontal::mapToSource(const QModelIndex &proxyIndex) const {
  if (sourceModel()) {
    return sourceModel()->index(proxyIndex.column(), proxyIndex.row());
  } else {
    return QModelIndex();
  }
}

QModelIndex HomestayDetailHorizontal::mapFromSource(const QModelIndex &sourceIndex) const {
  return index(sourceIndex.column(), sourceIndex.row());
}

QModelIndex HomestayDetailHorizontal::index(int row, int column, const QModelIndex &) const {
  return createIndex(row, column, (void*) 0);
}

QModelIndex HomestayDetailHorizontal::parent(const QModelIndex &) const {
  return QModelIndex();
}

int HomestayDetailHorizontal::rowCount(const QModelIndex &) const {
  return sourceModel() ? sourceModel()->columnCount() : 0;
}

int HomestayDetailHorizontal::columnCount(const QModelIndex &) const {
  return sourceModel() ? sourceModel()->rowCount() : 0;
}

QVariant HomestayDetailHorizontal::headerData(
           int section, Qt::Orientation orientation, int role) const {
  if (!sourceModel()) { return QVariant(); }
  Qt::Orientation new_orientation = orientation == Qt::Horizontal ?
      Qt::Vertical : Qt::Horizontal;
  return sourceModel()->headerData(section, new_orientation, role);
}

#endif // HomestayDetailHorizontal_H
