#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>

#include "model.h"

#define WIN_TITLE "Parser"

namespace PARSER {

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    void MainMenu();
    void MainActions();
    void Table();
    void Connections();

    QString fileName;
    QString separator;

    QToolBar *m_toolBar;

    QAction *action_import;
    QAction *action_export;
    QAction *action_changeSep;
    QAction *action_exit;

    QTableView *view;
    QStandardItemModel *model;

    void closeEvent(QCloseEvent *event) override;

private slots:
    void slot_actionImport();
    void slot_actionExport();
    void slot_actionChangeSep();
};

} //PARSER
#endif // MAINWINDOW_H
