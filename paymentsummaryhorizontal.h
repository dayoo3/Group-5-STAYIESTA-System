#ifndef PaymentSummaryHorizontal_H
#define PaymentSummaryHorizontal_H

#include "QAbstractProxyModel"

class PaymentSummaryHorizontal : public QAbstractProxyModel {
public:
  PaymentSummaryHorizontal(QObject* parent = nullptr);
  QModelIndex mapToSource(const QModelIndex &proxyIndex) const;
  QModelIndex mapFromSource(const QModelIndex &sourceIndex) const;
  QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
  QModelIndex parent(const QModelIndex &child) const;
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

PaymentSummaryHorizontal::PaymentSummaryHorizontal(QObject *parent) :
  QAbstractProxyModel(parent) {
}

QModelIndex PaymentSummaryHorizontal::mapToSource(const QModelIndex &proxyIndex) const {
  if (sourceModel()) {
    return sourceModel()->index(proxyIndex.column(), proxyIndex.row());
  } else {
    return QModelIndex();
  }
}

QModelIndex PaymentSummaryHorizontal::mapFromSource(const QModelIndex &sourceIndex) const {
  return index(sourceIndex.column(), sourceIndex.row());
}

QModelIndex PaymentSummaryHorizontal::index(int row, int column, const QModelIndex &) const {
  return createIndex(row, column, (void*) 0);
}

QModelIndex PaymentSummaryHorizontal::parent(const QModelIndex &) const {
  return QModelIndex();
}

int PaymentSummaryHorizontal::rowCount(const QModelIndex &) const {
  return sourceModel() ? sourceModel()->columnCount() : 0;
}

int PaymentSummaryHorizontal::columnCount(const QModelIndex &) const {
  return sourceModel() ? sourceModel()->rowCount() : 0;
}

QVariant PaymentSummaryHorizontal::headerData(
           int section, Qt::Orientation orientation, int role) const {
  if (!sourceModel()) { return QVariant(); }
  Qt::Orientation new_orientation = orientation == Qt::Horizontal ?
      Qt::Vertical : Qt::Horizontal;
  return sourceModel()->headerData(section, new_orientation, role);
}

#endif // PaymentSummaryHorizontal_H
