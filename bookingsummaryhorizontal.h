#ifndef BOOKINGSUMMARYHORIZONTAL_H
#define BOOKINGSUMMARYHORIZONTAL_H

#include "QAbstractProxyModel"

class BookingSummaryHorizontal : public QAbstractProxyModel {
public:
  BookingSummaryHorizontal(QObject* parent = nullptr);
  QModelIndex mapToSource(const QModelIndex &proxyIndex) const;
  QModelIndex mapFromSource(const QModelIndex &sourceIndex) const;
  QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
  QModelIndex parent(const QModelIndex &child) const;
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

BookingSummaryHorizontal::BookingSummaryHorizontal(QObject *parent) :
  QAbstractProxyModel(parent) {
}

QModelIndex BookingSummaryHorizontal::mapToSource(const QModelIndex &proxyIndex) const {
  if (sourceModel()) {
    return sourceModel()->index(proxyIndex.column(), proxyIndex.row());
  } else {
    return QModelIndex();
  }
}

QModelIndex BookingSummaryHorizontal::mapFromSource(const QModelIndex &sourceIndex) const {
  return index(sourceIndex.column(), sourceIndex.row());
}

QModelIndex BookingSummaryHorizontal::index(int row, int column, const QModelIndex &) const {
  return createIndex(row, column, (void*) 0);
}

QModelIndex BookingSummaryHorizontal::parent(const QModelIndex &) const {
  return QModelIndex();
}

int BookingSummaryHorizontal::rowCount(const QModelIndex &) const {
  return sourceModel() ? sourceModel()->columnCount() : 0;
}

int BookingSummaryHorizontal::columnCount(const QModelIndex &) const {
  return sourceModel() ? sourceModel()->rowCount() : 0;
}

QVariant BookingSummaryHorizontal::headerData(
           int section, Qt::Orientation orientation, int role) const {
  if (!sourceModel()) { return QVariant(); }
  Qt::Orientation new_orientation = orientation == Qt::Horizontal ?
      Qt::Vertical : Qt::Horizontal;
  return sourceModel()->headerData(section, new_orientation, role);
}

#endif // BOOKINGSUMMARYHORIZONTAL_H
