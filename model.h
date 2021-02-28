#ifndef MODEL_H
#define MODEL_H

#include <QStandardItemModel>

namespace PARSER {
class Model {
public:
    Model();
    virtual ~Model();

    QStandardItemModel* importModel(QString, QString);
    int exportModel(QStandardItemModel*);
};
} //PARSER

#endif // MODEL_H
