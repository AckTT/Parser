#include "parseapp.h"

PARSE::ParseApp::ParseApp(int argc, char **argv) : QCoreApplication(argc, argv) {
setApplicationName("Parser");
setApplicationVersion("1.0.0");
}

PARSE::ParseApp::~ParseApp() {}
