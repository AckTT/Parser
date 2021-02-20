#ifndef PARSEAPP_H
#define PARSEAPP_H

#include <QCoreApplication>

namespace PARSE {
    class ParseApp : public QCoreApplication {
    public:
        ParseApp(int, char**);
        virtual ~ParseApp();
    };
} //PARSE

#endif // PARSEAPP_H
