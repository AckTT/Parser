#ifndef PARSEAPP_H
#define PARSEAPP_H

#include <QApplication>

namespace PARSER {
    class ParseApp : public QApplication {
    public:
        ParseApp(int, char**);
        virtual ~ParseApp();
    };
} //PARSE

#endif // PARSEAPP_H
