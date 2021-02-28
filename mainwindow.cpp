#include "mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QInputDialog>

#include "parseapp.h"

namespace PARSER {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    MainActions();
    MainMenu();
    Connections();
    Table();

    //Tool bar -----------------------------------------------------------
    m_toolBar = new QToolBar(this);
    m_toolBar->addAction(action_import);
//    m_toolBar->addAction(action_export);
    addToolBar(Qt::TopToolBarArea,m_toolBar);
    //Status bar ---------------------------------------------------------
    statusBar()->show();
    statusBar()->showMessage(tr("Welcome!"), 3000);
    //Main window setup --------------------------------------------------
    setMinimumSize(640, 480);
    setWindowTitle(WIN_TITLE);
    setCentralWidget(view);
    separator = ";";
}

void MainWindow::Table() {
    view = new QTableView(this);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::MainActions() {
    action_import = new QAction(tr("Import"), this);
//    action_export = new QAction(tr("Export"), this);
    action_exit = new QAction(tr("Exit"), this);
    action_import->setShortcut(tr("CTRL+O"));
//    action_export->setShortcut(tr("CTRL+S"));
    action_changeSep = new QAction(tr("Change separator"), this);
    action_exit->setShortcut(tr("CTRL+Q"));
}

void MainWindow::MainMenu() {
    QMenu *menu;
    menu = menuBar()->addMenu(tr("File"));
    menu->addAction(action_import);
//    menu->addAction(action_export);
    menu->addSeparator();
    menu->addAction(action_changeSep);
    menu->addSeparator();
    menu->addAction(action_exit);
}

void MainWindow::Connections() {
    connect(action_import, SIGNAL(triggered()), this, SLOT(slot_actionImport()));
//    connect(action_export, SIGNAL(triggered()), this, SLOT(slot_actionExport()));
    connect(action_changeSep, SIGNAL(triggered()), this, SLOT(slot_actionChangeSep()));
    connect(action_exit, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::slot_actionImport() {
    Model m;
    fileName = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::homePath(),tr("Text files(*.txt);;Any files(*.*)"));
    if (fileName.isEmpty())
        statusBar()->showMessage("File not opened", 2000);
    else {
        model = m.importModel(fileName, separator);
        view->setModel(model);
    }
}

void MainWindow::slot_actionExport() {

}

void MainWindow::slot_actionChangeSep() {
    separator = QInputDialog::getText(this, tr("Input"), tr("Separator:"), QLineEdit::Normal, separator);
}

void MainWindow::closeEvent(QCloseEvent *closeEvent) {
    if (QMessageBox::question(this, tr("Confirmation"), tr("Are you Sure you want to exit?"), QMessageBox::Cancel|QMessageBox::Yes)
                == QMessageBox::Cancel)
            closeEvent->ignore();
        else
            closeEvent->accept();
}

MainWindow::~MainWindow() {}

} //PARSER
