#include <QFile>

#include "model.h"

namespace PARSER {
Model::Model() {}
Model::~Model(){}

QStandardItemModel* Model::importModel(QString name, QString sep) {
    QStandardItemModel* model = new QStandardItemModel();
    QList<QStandardItem*> list;

    QFile file(name);
    file.open(QIODevice::ReadOnly);

    QTextStream fileStream(&file);
    QString line;
    while (fileStream.readLineInto(&line)) {
        foreach(QString i, line.split(sep)) {
            list.append(new QStandardItem(i));
        }
        model->appendRow(list);
        list.clear();
    }
    file.close();
    return model;
}

int Model::exportModel(QStandardItemModel*) {
    return 0;
}
} //PARSER
