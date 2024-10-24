#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口名和图标
    setWindowTitle("NPUscanner");
    setWindowIcon(QIcon("./ico/scanner3.ico"));

    //连接button和slot
    connect(ui->runpy_pushButton, SIGNAL(clicked(bool)), this, SLOT(runPythonScript()));

    //设置文本框为只读，作为显示输出的框
    ui->textOutput->setReadOnly(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runPythonScript(void)
{
    QProcess* process = new QProcess(this);
    process->start("python", QStringList() << "test.py");
    process->waitForFinished(); // 可选，等待脚本执行完成

    QString output = process->readAllStandardOutput();

    QString error = process->readAllStandardError();

    // 显示输出和错误信息
    ui->textOutput->append("Output:\n" + output);
    ui->textOutput->append("Error:\n" + error);
}