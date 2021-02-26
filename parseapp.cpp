#include "parseapp.h"

PARSER::ParseApp::ParseApp(int argc, char **argv) : QApplication(argc, argv) {
    setOrganizationName("MSR");
    setOrganizationDomain("MSR.com");
    setApplicationName("Parser");
    setApplicationVersion("1.0.0");
}

PARSER::ParseApp::~ParseApp() {}
